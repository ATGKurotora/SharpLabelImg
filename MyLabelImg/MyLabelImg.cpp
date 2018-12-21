#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QPixmap>
#include "MyLabelImg.h"
#include "MyFile.h"

MyLabelImg::MyLabelImg(QWidget *parent)
	: QMainWindow(parent),
	imgPtr(0)
{
	ui.setupUi(this);
	connect(ui.browseButton, &QPushButton::clicked, this, &MyLabelImg::browseImg);
	connect(ui.prevButton, &QPushButton::clicked, this, &MyLabelImg::previousImg);
	connect(ui.nextButton, &QPushButton::clicked, this, &MyLabelImg::nextImg);
	connect(ui.saveButton, &QPushButton::clicked, this, &MyLabelImg::saveImg);
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

void	MyLabelImg::saveImg()
{
	QString saveDirString = ui.saveLineEdit->text();
	if (saveDirString.isEmpty() || !QDir(saveDirString).exists())
	{
		saveDirString = QFileDialog::getExistingDirectory(this, tr("Open directory"), "/home", QFileDialog::ShowDirsOnly);
		ui.saveLineEdit->setText(saveDirString);
	}
		
	MyFile	file;

	if (!QDir(saveDirString + "/img").exists())
		QDir().mkdir(saveDirString + "/img");
	if (!QDir(saveDirString + "/data").exists())
		QDir().mkdir(saveDirString + "/data");

	if (myImage.getAbsolutePath().endsWith(".png"))
	{
		QFile::rename(myImage.getAbsolutePath(), saveDirString + "/img/" + QString::number(imgPtr) + ".png");
		listImg[imgPtr].setAbsolutePath(saveDirString + "/img/" + QString::number(imgPtr) + ".png");
	}
	else if (myImage.getAbsolutePath().endsWith(".jpg"))
	{
		QFile::rename(myImage.getAbsolutePath(), saveDirString + "/img/" + QString::number(imgPtr) + ".jpg");
		listImg[imgPtr].setAbsolutePath(saveDirString + "/img/" + QString::number(imgPtr) + ".jpg");
	}
	else
	{
		QFile::rename(myImage.getAbsolutePath(), saveDirString + "/img/" + QString::number(imgPtr) + ".jpeg");
		listImg[imgPtr].setAbsolutePath(saveDirString + "/img/" + QString::number(imgPtr) + ".jpeg");
	}
	refreshImg();
	file.saveData(myImage, saveDirString + "/data/" + QString::number(imgPtr) + ".xml");
}

void	MyLabelImg::refreshImg()
{
	if (!this->listImg.isEmpty())
	{
		myImage = listImg.at(imgPtr);
		ui.imgLabel->setPixmap(myImage.loadPixmap().scaled(1000, 1000, Qt::KeepAspectRatio));
	}
}