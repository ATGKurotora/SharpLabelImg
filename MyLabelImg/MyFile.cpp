#include "MyFile.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessagebox>

MyFile::MyFile() : _absolutePath("")
{
}

MyFile::~MyFile()
{
}

QString	MyFile::getStrLabData(MyImg img)
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

QString	MyFile::getStrData(MyImg img)
{
	QString ret = "";

	ret = "<annotation>\n\t";
	ret += "<folder>img</folder>\n\t";
	ret += "<filename>" + img.getAbsolutePath().split("/").at(img.getAbsolutePath().split("/").size() - 1) + "</filename>\n\t";
	ret += "<path>../img/" + img.getAbsolutePath().split("/").at(img.getAbsolutePath().split("/").size() - 1) + "</path>\n\t";
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

void	MyFile::saveData(MyImg img)
{
	if (!_absolutePath.isEmpty())
	{
		QFile myFile(_absolutePath);

		if (myFile.open(QIODevice::ReadWrite)) {
			QTextStream stream(&myFile);
			stream << getStrData(img) << endl;
			myFile.close();
		}
	}
	else 
	{
		QMessageBox msgBox;
		msgBox.setText("Unable to save data");
		msgBox.setIcon(QMessageBox::Critical);
		msgBox.exec();
	}
}

void	MyFile::saveData(MyImg img, QString absolutePath)
{
	setAbsolutePath(absolutePath);
	saveData(img);
}

void	MyFile::setAbsolutePath(QString absolutePath)
{
	_absolutePath = absolutePath;
}

QString	MyFile::getAbsolutePath()
{
	return _absolutePath;
}