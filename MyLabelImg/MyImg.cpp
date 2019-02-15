#include "MyImg.h"

MyImg::MyImg() : myImgPath(""), myDataPath("")
{
}


MyImg::~MyImg()
{
}

MyImg				&MyImg::operator=(const MyImg& other)
{
	if (this != &other)
	{
		this->myImgPath = other.myImgPath;
		this->listLabelInfo.clear();
		this->listLabelInfo.append(other.listLabelInfo);
	}

	return *this;
}

void				MyImg::setMyImgPath(QString imgPath)
{
	myImgPath = imgPath;
}

void				MyImg::setMyDataPath(QString dataPath)
{
	myDataPath = dataPath;
}

void				MyImg::addLabelInfo(LabelInfo labelInfo)
{
	listLabelInfo.append(labelInfo);
}

void				MyImg::removeLastLabelInfo()
{
	listLabelInfo.pop_back();
}

QPixmap				&MyImg::getCurrentPixmap()
{
	if (myCanevas.getCurrentPixmapId() == -1)
	{
		QPixmap	*imgPixmap = new QPixmap(myImgPath);
		myCanevas.addPixmap(imgPixmap);
	}

	return *(myCanevas.getMyPixmap(myCanevas.getCurrentPixmapId()));
}

xyInt				MyImg::getSize()
{
	xyInt ret;

	QPixmap img(myImgPath);
	ret.x = img.width();
	ret.y = img.height();
	return ret;
}

QString				MyImg::getMyImgPath()
{
	return myImgPath;
}

QString				MyImg::getMyDataPath()
{
	return myDataPath;
}

QVector<LabelInfo>	MyImg::getLabelInfo()
{
	return listLabelInfo;
}

xyInt				MyImg::getMyFirstPointI()
{
	return myCanevas.getMyFirstPoint();
}

void				MyImg::setMyFirstPointI(xyInt point, QColor color)
{
	myCanevas.setMyFirstPoint(point, color);
}

xyInt				MyImg::getMySecondPointI()
{
	return myCanevas.getMySecondPoint();
}

void				MyImg::setMySecondPointI(xyInt point)
{
	myCanevas.setMySecondPoint(point);
}

void				MyImg::setMyTmpPointI(xyInt point)
{
	myCanevas.setMyTmpPoint(point);
}

int					MyImg::getCurrentPixmapIdI()
{
	return myCanevas.getCurrentPixmapId();
}

void				MyImg::removePixmapI(int id)
{
	myCanevas.removePixmap(id);
}

bool				MyImg::getWaitingSecondPointI()
{
	return myCanevas.getWaitingSecondPoint();
}

void				MyImg::setWaitingSecondPointI(bool yesNo)
{
	myCanevas.setWaitingSecondPoint(yesNo);
}