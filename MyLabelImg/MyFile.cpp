#include "MyFile.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessagebox>

MyFile::MyFile() : myImgFolderPath("")
{
}

MyFile::~MyFile()
{
}

void		MyFile::saveData(MyImg img)
{
	QFile myFile(img.getMyDataPath());

	if (myFile.open(QIODevice::ReadWrite)) {
		QTextStream stream(&myFile);
		stream << getStrData(img) << endl;
		myFile.close();
	}
}

void		MyFile::checkAndCreateFolder()
{
	if (!QDir(myImgFolderPath + "/img").exists())
		QDir().mkdir(myImgFolderPath + "/img");
	if (!QDir(myImgFolderPath + "/data").exists())
		QDir().mkdir(myImgFolderPath + "/data");
}

void		MyFile::changeImgAndDataPath(MyImg &img)
{
	QString imgPath = myImgFolderPath + "/img/";
	QString dataPath = myImgFolderPath + "/data/";
	QString nbFile = QString::number(getNumImg());
	QString imgExt = getImgExt(img);

	QFile::rename(img.getMyImgPath(), imgPath + nbFile + imgExt);
	img.setMyImgPath(imgPath + nbFile + imgExt);
	img.setMyDataPath(dataPath + nbFile + ".xml");
}

QString		MyFile::getStrLabData(MyImg img)
{
	int i = 0;
	QVector<LabelInfo>	labInfs = img.getLabelInfo();
	QString ret = "";

	while (i < labInfs.size())
	{
		ret += "<object>\n\t\t";
		ret += "<name>" + labInfs[i].getLabelName() + "</name>\n\t\t";
		ret += "<pose>Unspecified</pose>\n\t\t";
		ret += "<truncated>0</truncated>\n\t\t";
		ret += "<difficult>0</difficult>\n\t\t";
		ret += "<bndbox>\n\t\t\t";
		ret += "<xmin>" + QString::number(labInfs[i].getFirstPoint().x) + "</xmin>\n\t\t\t";
		ret += "<ymin>" + QString::number(labInfs[i].getFirstPoint().y) + "</ymin>\n\t\t\t";
		ret += "<xmax>" + QString::number(labInfs[i].getSecondPoint().x) + "</xmax>\n\t\t\t";
		ret += "<ymax>" + QString::number(labInfs[i].getSecondPoint().y) + "</ymax>\n\t\t";
		ret += "</bndbox>\n\t";
		ret += "<object>\n";
		if (i + 1 < labInfs.size())
			ret += "\t";
		i++;
	}

	return ret;
}

QString		MyFile::getStrData(MyImg img)
{
	QString ret = "";

	ret = "<annotation>\n\t";
	ret += "<folder>img</folder>\n\t";
	ret += "<filename>" + img.getMyImgPath().split("/").at(img.getMyImgPath().split("/").size() - 1) + "</filename>\n\t";
	ret += "<path>../img/" + img.getMyImgPath().split("/").at(img.getMyImgPath().split("/").size() - 1) + "</path>\n\t";
	ret += "<source>\n\t\t";
	ret += "<database>Unknwon</database>\n\t";
	ret += "</source>\n\t";
	ret += "<size>\n\t\t";
	ret += "<width>" + QString::number(img.getSize().x) + "</width>\n\t\t";
	ret += "<height>" + QString::number(img.getSize().y) + "</height>\n\t\t";
	ret += "<depth>3</depth>\n\t";
	ret += "</size>\n\t";
	ret += "<segmented>0</segmented>\n\t";
	ret += getStrLabData(img);
	ret += "</annotation>";

	return ret;
}

QString		MyFile::getImgExt(MyImg img)
{
	QString ret = img.getMyImgPath();

	ret = "." + ret.split(".").back();

	return ret;
}

int			MyFile::getNumImg()
{
	int		ret = 0;
	int		i = 0;
	bool	ok;
	QStringList imgFileList = getImgFileList(myImgFolderPath + "/img");

	for each (QString imgFile in imgFileList)
	{
		i = imgFile.split('.').at(0).toInt(&ok);
		if (ok == true && i >= ret)
			ret = i + 1;
	}

	return ret;
}

void		MyFile::saveMyImg(MyImg &img)
{
	if (!myImgFolderPath.isEmpty())
	{
		checkAndCreateFolder();
		if (img.getMyDataPath().isEmpty() ||
			!QFile(img.getMyDataPath()).exists())
			changeImgAndDataPath(img);
		if (QFile(img.getMyDataPath()).exists())
			QFile(img.getMyDataPath()).remove();
		saveData(img);
	}
	else
	{
		QMessageBox msgBox;
		msgBox.setText("Unable to save data");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
	}
}

void		MyFile::setMyImgFolderPath(QString imgFolderPath)
{
	myImgFolderPath = imgFolderPath;
}

QString		MyFile::getMyImgFolderPath()
{
	return myImgFolderPath;
}

QStringList	MyFile::getImgFileList(QString imgDirStr)
{
	QDir imgDir = QDir(imgDirStr);
	QStringList	filtersName;
	filtersName << "*.png" << "*.jpg" << "*.jpeg";
	QStringList imgFileList = imgDir.entryList(filtersName, QDir::Files, QDir::Name);

	return imgFileList;
}