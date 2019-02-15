#pragma once
#include "LabelInfo.h"
#include "Canevas.h"
#include <QPixmap>

class MyImg
{
public:
	MyImg();
	~MyImg();
	MyImg				&operator=(const MyImg&);
	void				setMyImgPath(QString);
	void				setMyDataPath(QString);
	void				addLabelInfo(LabelInfo);
	void				removeLastLabelInfo();
	QPixmap				&getCurrentPixmap();
	xyInt				getSize();
	QString				getMyImgPath();
	QString				getMyDataPath();
	QVector<LabelInfo>	getLabelInfo();
	xyInt				getMyFirstPointI();
	void				setMyFirstPointI(xyInt, QColor);
	xyInt				getMySecondPointI();
	void				setMySecondPointI(xyInt);
	void				setMyTmpPointI(xyInt);
	int					getCurrentPixmapIdI();
	void				removePixmapI(int);
	bool				getWaitingSecondPointI();
	void				setWaitingSecondPointI(bool);

private:
	QString				myImgPath;
	QString				myDataPath;
	QVector<LabelInfo>	listLabelInfo;
	Canevas				myCanevas;
};

