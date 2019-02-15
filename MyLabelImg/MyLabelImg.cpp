#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QPixmap>
#include <QShortcut>
#include "MyLabelImg.h"

MyLabelImg::MyLabelImg(QWidget *parent)
	: QMainWindow(parent),
	imgPtr(0)
{
	myFile = MyFile();
	ui.setupUi(this);
	mySignalMapper = new QSignalMapper(this);
	connect(ui.browseButton, &QPushButton::clicked, this, &MyLabelImg::browseImg);
	connect(ui.prevButton, &QPushButton::clicked, this, &MyLabelImg::previousImg);
	connect(ui.nextButton, &QPushButton::clicked, this, &MyLabelImg::nextImg);
	connect(ui.saveButton, &QPushButton::clicked, this, &MyLabelImg::saveImgButton);
	connect(ui.useLabelButton, &QPushButton::clicked, this, &MyLabelImg::saveLabel);
	connect(ui.imgLabel, SIGNAL(Mouse_Moved()), this, SLOT(MouseMoved()));
	connect(ui.imgLabel, SIGNAL(Mouse_Pressed()), this, SLOT(MousePressed()));
	connect(mySignalMapper, SIGNAL(mapped(QString)), this, SLOT(selectCurrentLabel(QString)));
}

MyLabelImg::~MyLabelImg()
{}

void	MyLabelImg::browseImg()
{
	//get a list of all picture in the image directory choosed
	QString imgDirString = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/home", QFileDialog::ShowDirsOnly);
	QStringList imgFileList = myFile.getImgFileList(imgDirString);

	//add all images to the list
	for each (QString imgFile in imgFileList)
	{
		MyImg	img;
		img.setMyImgPath(imgDirString + '/' + imgFile);
		this->listImg.append(img);
	}

	//refresh ui
	refreshImg();
	ui.browseLabel->setText("Images from: " + imgDirString);
}

void	MyLabelImg::previousImg()
{
	if (imgPtr > 0)
	{
		imgPtr = imgPtr - 1;
		refreshImg();
	}
}

void	MyLabelImg::nextImg()
{
	saveImg();
	if (imgPtr + 1 < listImg.count())
	{
		imgPtr = imgPtr + 1;
		refreshImg();
	}
}

void	MyLabelImg::saveImgButton()
{
	//get folder to save picture
	QString saveDirString = ui.saveLineEdit->text();
	if (saveDirString.isEmpty() || !QDir(saveDirString).exists())
	{
		saveDirString = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/home", QFileDialog::ShowDirsOnly);
		ui.saveLineEdit->setText(saveDirString);
	}
	myFile.setMyImgFolderPath(saveDirString);
	
	//check if listImg[imgPtr] exist
	if (listImg.size() > imgPtr)
	{
		//save current img
		myFile.saveMyImg(listImg[imgPtr]);

		//refresh ui
		refreshImg();
	}
}

void	MyLabelImg::saveLabel()
{
	//check if label already is in the label list
	QString labelName = this->ui.nameLabelLineEdit->text();
	if (myListLabelButton.isNotInList(labelName))
	{
		//init elements
		QPushButton	*newButton = new QPushButton(this);
		int pos = myListLabelButton.getPosNewButton();

		//set connection with button
		mySignalMapper->setMapping(newButton, labelName);
		connect(newButton, SIGNAL(clicked()), mySignalMapper, SLOT(map()));

		//add and display the button
		myListLabelButton.addLabelButton(newButton, labelName, pos);
		selectCurrentLabel(labelName);
		refreshListLabelButton();
	}
}

void	MyLabelImg::selectCurrentLabel(QString labelName)
{
	//inc the value used of the button
	myListLabelButton.incButtonLabel(labelName);
	
	//set text to display labelName
	ui.nameLabel->setText("actual label: " + labelName);
	
	//get pos of button in list
	int pos = myListLabelButton.getPosButton(labelName);

	//set current label and color used
	myCurrentLabel = labelName;
	myCurrentColor = myListLabelButton.getButtonColor(pos);
	
	//reset creation square
	if (listImg.size() > imgPtr)
		listImg[imgPtr].setWaitingSecondPointI(false);
}

void	MyLabelImg::saveImg()
{
	myFile.saveMyImg(listImg[imgPtr]);
}

void	MyLabelImg::refreshImg()
{
	if (!this->listImg.isEmpty())
	{
		listImg[imgPtr] = listImg.at(imgPtr);
		ui.imgLabel->setPixmap(listImg[imgPtr].getCurrentPixmap().scaled(1000, 800));
	}
}

void	MyLabelImg::refreshListLabelButton()
{
	clearLayout(ui.vLListLabel);
	QVector<LabelButton>	myList = myListLabelButton.getMyListButton();
	int	i = 0;

	if (myList.size() > 0)
	{
		while (i < myList.size())
		{
			myList[i].getMyButton()->setStyleSheet(myListLabelButton.getButtonColorStr(i));
			ui.vLListLabel->addWidget(myList[i].getMyButton());
			myList[i].getMyButton()->setShortcut(QKeySequence(((i + 1) % 10) + 48));
			i++;
		}
	}
}

void	MyLabelImg::clearLayout(QLayout *layout)
{
	QLayoutItem				*item;
	int i = 0;

	while (i < layout->count())
	{
		item = layout->itemAt(i);
		QWidget *widget = item->widget();
		layout->removeWidget(widget);
	}
}

void	MyLabelImg::MouseMoved()
{
	if (listImg.size() > 0 && listImg[imgPtr].getWaitingSecondPointI() == true)
	{
		xyInt	pos;
		pos.x = ui.imgLabel->getX();
		pos.y = ui.imgLabel->getY();

		pos = getTrueCoordinate(pos);
		listImg[imgPtr].removePixmapI(listImg[imgPtr].getCurrentPixmapIdI());
		listImg[imgPtr].setMyTmpPointI(pos);
		refreshImg();
	}
}

void	MyLabelImg::MousePressed()
{
	if (!(myCurrentLabel.isEmpty()))
	{
		xyInt	pos;
		pos.x = ui.imgLabel->getX();
		pos.y = ui.imgLabel->getY();
		
		pos = getTrueCoordinate(pos);
		if (listImg[imgPtr].getWaitingSecondPointI() == false)
			listImg[imgPtr].setMyFirstPointI(pos, myCurrentColor);
		else
		{
			listImg[imgPtr].setMySecondPointI(pos);
			LabelInfo	infoLabel(myCurrentLabel);
			infoLabel.setPoints(listImg[imgPtr].getMyFirstPointI(), listImg[imgPtr].getMySecondPointI());
			listImg[imgPtr].addLabelInfo(infoLabel);
		}
		refreshImg();
	}
}

xyInt	MyLabelImg::getTrueCoordinate(xyInt pos)
{
	xyInt	tPos;
	tPos.x = pos.x * listImg[imgPtr].getSize().x / 1000;
	tPos.y = pos.y *listImg[imgPtr].getSize().y / 800;

	return tPos;
}