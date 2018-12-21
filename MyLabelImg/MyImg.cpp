#include "MyImg.h"

MyImg::MyImg()
{
}


MyImg::~MyImg()
{
}

MyImg	&MyImg::operator=(const MyImg& other)
{
	this->_absolutePath = other._absolutePath;
	this->listLabelInfo.clear();
	this->listLabelInfo.append(other.listLabelInfo);

	return *this;
}

void MyImg::setAbsolutePath(QString absolutePath)
{
	this->_absolutePath = absolutePath;
}

void MyImg::setLabelList(QVector<LabelInfo> labelList)
{
	this->listLabelInfo.clear();
	this->listLabelInfo.append(listLabelInfo);
}

QPixmap &MyImg::loadPixmap()
{
	QPixmap	*imgPixmap = new QPixmap(_absolutePath);

	return *imgPixmap;
}

xyInt MyImg::getSize()
{
	xyInt ret;

	QPixmap img(_absolutePath);
	ret.x = img.width();
	ret.y = img.height();
	return ret;
}

QString MyImg::getAbsolutePath()
{
	return this->_absolutePath;
}

QVector<LabelInfo> MyImg::getLabelInfo()
{
	return this->listLabelInfo;
}
