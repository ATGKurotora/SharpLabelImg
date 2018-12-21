#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QPixmap>
#include "MyLabelImg.h"

MyLabelImg::MyLabelImg(QWidget *parent)
	: QMainWindow(parent),
	imgPtr(0)
{
	ui.setupUi(this);
	connect(ui.browseButton, &QPushButton::clicked, this, &MyLabelImg::browseImg);
	connect(ui.prevButton, &QPushButton::clicked, this, &MyLabelImg::previousImg);
	connect(ui.nextButton, &QPushButton::clicked, this, &MyLabelImg::nextImg);
}

MyLabelImg::~MyLabelImg()
{}

void	MyLabelImg::browseImg()
{
	QString imgDirString = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/home", QFileDialog::ShowDirsOnly);
	QDir imgDir = QDir(imgDirString);
	QStringList	filtersName;
	filtersName << "*.png" << "*.jpg" << "*.jpeg";
	QStringList imgFileList = imgDir.entryList(filtersName, QDir::Files, QDir::Name);
	for each (QString imgFile in imgFileList)
	{
		MyImg	img;
		img.setAbsolutePath(imgDirString + '/' + imgFile);
		this->listImg.append(img);
	}
	refreshImg();
	ui.browseLineEdit->setText(imgDirString);
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
	if (imgPtr + 1 < listImg.count())
	{
		imgPtr = imgPtr + 1;
		refreshImg();
	}
}

void	MyLabelImg::refreshImg()
{
	if (!this->listImg.isEmpty())
	{
		myImage = listImg.at(imgPtr);
		ui.imgLabel->setPixmap(myImage.loadPixmap().scaled(1000, 1000, Qt::KeepAspectRatio));
	}
}