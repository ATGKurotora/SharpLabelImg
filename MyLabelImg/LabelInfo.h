#pragma once
#include "Data.h"
#include <QString>

class LabelInfo
{
public:
	LabelInfo();
	LabelInfo(QString labelName);
	LabelInfo(QString labelName, xyInt firstPoint, xyInt secondPoint);
	LabelInfo(const LabelInfo& other);
	~LabelInfo();
	LabelInfo	&operator=(const LabelInfo& other);

	void		setPoints(xyInt firstPoint, xyInt secondPoint);
	void		setLabelName(QString labelName);
	xyInt		getFirstPoint();
	xyInt		getSecondPoint();
	QString		getLabelName() const;

private:
	xyInt		firstPoint;
	xyInt		secondPoint;
	QString		labelName;
};

