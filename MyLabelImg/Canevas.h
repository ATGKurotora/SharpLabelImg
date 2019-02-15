#pragma once
#include <QVector>
#include <QPixmap>
#include <QPainter>
#include "Data.h"

class Canevas
{
public:
	Canevas();
	Canevas(QPixmap *);
	~Canevas();
	int					getCurrentPixmapId();
	void				setCurrentPixmapId(int);
	xyInt				getMyFirstPoint();
	void				setMyFirstPoint(xyInt, QColor);
	xyInt				getMySecondPoint();
	void				setMySecondPoint(xyInt);
	void				setMyTmpPoint(xyInt);
	QPixmap				*getMyPixmap(int);
	void				addPixmap(QPixmap *);
	void				removePixmap(int);
	bool				getWaitingSecondPoint();
	void				setWaitingSecondPoint(bool);

private:
	int					currentPixmapId;
	xyInt				myFirstPoint;
	xyInt				mySecondPoint;
	xyInt				myTmpPoint;
	bool				waitingSecondPoint;
	QPainter			*myPainter;
	QColor				myColor;
	QVector<QPixmap*>	myPixList;

private:
	void				getProperPoints();
	void				drawSquare();
	void				drawTmpSquare(int, int, int, int);
};

