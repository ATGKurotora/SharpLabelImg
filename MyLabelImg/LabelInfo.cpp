#include "LabelInfo.h"

LabelInfo::LabelInfo()
{}

LabelInfo::LabelInfo(QString labelName) : labelName(labelName)
{}

LabelInfo::LabelInfo(QString labelName, xyInt firstPoint, xyInt secondPoint) :
	labelName(labelName),
	firstPoint(firstPoint),
	secondPoint(secondPoint)
{}

LabelInfo::LabelInfo(const LabelInfo& other)
{
	this->labelName = other.labelName;
	this->firstPoint.x = other.firstPoint.x;
	this->secondPoint.x = other.secondPoint.x;
	this->firstPoint.y = other.firstPoint.y;
	this->secondPoint.y = other.secondPoint.y;
}

LabelInfo::~LabelInfo()
{}

LabelInfo	&LabelInfo::operator=(const LabelInfo& other)
{
	if (this != &other)
	{
		this->labelName = other.labelName;
		this->firstPoint.x = other.firstPoint.x;
		this->secondPoint.x = other.secondPoint.x;
		this->firstPoint.y = other.firstPoint.y;
		this->secondPoint.y = other.secondPoint.y;
	}

	return *this;
}

void LabelInfo::setPoints(xyInt firstPoint, xyInt secondPoint)
{
	this->firstPoint.x = firstPoint.x;
	this->secondPoint.x = secondPoint.x;
	this->firstPoint.y = firstPoint.y;
	this->secondPoint.y = secondPoint.y;
}

void LabelInfo::setLabelName(QString labelName)
{
	this->labelName = labelName;
}

xyInt LabelInfo::getFirstPoint()
{
	return this->firstPoint;
}

xyInt LabelInfo::getSecondPoint()
{
	return this->secondPoint;
}

QString LabelInfo::getLabelName() const
{
	return this->labelName;
}

