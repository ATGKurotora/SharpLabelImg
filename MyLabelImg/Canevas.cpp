#include "Canevas.h"

Canevas::Canevas()
{
	currentPixmapId = -1;
	myPainter = new QPainter();
	waitingSecondPoint = false;
}

Canevas::Canevas(QPixmap *pixmap)
{
	myPixList.push_back(pixmap);
	currentPixmapId = 0;
	myPainter = new QPainter(myPixList[currentPixmapId]);
	waitingSecondPoint = false;
}

Canevas::~Canevas()
{}

int		Canevas::getCurrentPixmapId()
{
	return currentPixmapId;
}

void	Canevas::setCurrentPixmapId(int id)
{
	currentPixmapId = id;
}

xyInt	Canevas::getMyFirstPoint()
{
	return myFirstPoint;
}

void	Canevas::setMyFirstPoint(xyInt point, QColor color)
{
	myFirstPoint = point;
	myColor = color;
	waitingSecondPoint = true;
}

xyInt	Canevas::getMySecondPoint()
{
	return mySecondPoint;
}

void	Canevas::setMySecondPoint(xyInt point)
{
	mySecondPoint = point;
	waitingSecondPoint = false;
	getProperPoints();
	drawSquare();
}

void	Canevas::setMyTmpPoint(xyInt point)
{
	myTmpPoint = point;

	int xF = myFirstPoint.x;
	int yF = myFirstPoint.y;
	int xT = myTmpPoint.x;
	int yT = myTmpPoint.y;

	if (xF > xT)
	{
		xF = myTmpPoint.x;
		xT = myFirstPoint.x;
	}
	if (yF > yT)
	{
		yF = myTmpPoint.y;
		yT = myFirstPoint.y;
	}
	drawTmpSquare(xF, yF, xT, yT);
}

QPixmap	*Canevas::getMyPixmap(int id)
{
	return myPixList[id];
}

void	Canevas::addPixmap(QPixmap *pixmap)
{
	myPixList.push_back(pixmap);
	currentPixmapId++;
	if (currentPixmapId > 0)
		myPixList[currentPixmapId]->operator=(*myPixList[currentPixmapId - 1]);
	myPainter->end();
	delete myPainter;
	myPainter = new QPainter(myPixList[currentPixmapId]);
}

void	Canevas::removePixmap(int id)
{
	if (id > 0)
	{
		myPixList.remove(id);
		currentPixmapId = currentPixmapId - 1;
	}
}

void	Canevas::getProperPoints()
{
	int x = mySecondPoint.x;
	int y = mySecondPoint.y;

	if (myFirstPoint.x > x)
	{
		mySecondPoint.x = myFirstPoint.x;
		myFirstPoint.x = x;
	}
	if (myFirstPoint.y > y)
	{
		mySecondPoint.y = myFirstPoint.y;
		myFirstPoint.y = y;
	}
}

void	Canevas::drawSquare()
{
	QPen pen;
	pen.setColor(myColor);
	pen.setWidth(2);

	QPixmap *cpy = new QPixmap(myPixList[currentPixmapId]->width(), myPixList[currentPixmapId]->height());
	addPixmap(cpy);
	
	myPainter->setPen(pen);
	myPainter->drawRect(myFirstPoint.x, myFirstPoint.y, mySecondPoint.x - myFirstPoint.x, mySecondPoint.y - myFirstPoint.y);
}

void	Canevas::drawTmpSquare(int xF, int yF, int xT, int yT)
{
	QPen pen;
	pen.setColor(myColor);
	pen.setWidth(2);

	QPixmap *cpy = new QPixmap(myPixList[currentPixmapId]->width(), myPixList[currentPixmapId]->height());
	addPixmap(cpy);

	myPainter->setPen(pen);
	myPainter->drawRect(xF, yF, xT - xF, yT - yF);
}

bool	Canevas::getWaitingSecondPoint()
{
	return waitingSecondPoint;
}

void	Canevas::setWaitingSecondPoint(bool yesNo)
{
	waitingSecondPoint = yesNo;
}