#pragma once
#include "Data.h"
#include "LabelInfo.h"
#include <QPixmap>

class MyImg
{
public:
	MyImg();
	~MyImg();
	MyImg				&operator=(const MyImg& other);
	void				setAbsolutePath(QString absolutePath);
	void				setLabelList(QVector<LabelInfo> labelList);
	QPixmap				&loadPixmap();
	xyInt				getSize();
	QString				getAbsolutePath();
	QVector<LabelInfo>	getLabelInfo();

private:
	QString				absolutePath;
	QVector<LabelInfo>	listLabelInfo;
};

