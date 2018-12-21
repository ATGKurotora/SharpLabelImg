#include "MyImg.h"

MyImg::MyImg()
{
}


MyImg::~MyImg()
{
}

MyImg	&MyImg::operator=(const MyImg& other)
{
	this->absolutePath = other.absolutePath;
	this->listLabelInfo.clear();
	this->listLabelInfo.append(other.listLabelInfo);

	return *this;
}

void MyImg::setAbsolutePath(QString absolutePath)
{
	this->absolutePath = absolutePath;
}

void MyImg::setLabelList(QVector<LabelInfo> labelList)
{
	this->listLabelInfo.clear();
	this->listLabelInfo.append(listLabelInfo);
}

QPixmap &MyImg::loadPixmap()
{
	QPixmap	*imgPixmap = new QPixmap(absolutePath);

	return *imgPixmap;
}

xyInt MyImg::getSize()
{
	xyInt ret;

	ret.x = 10;
	ret.y = 10;
	return ret;
}

QString MyImg::getAbsolutePath()
{
	return this->absolutePath;
}

QVector<LabelInfo> MyImg::getLabelInfo()
{
	return this->listLabelInfo;
}
