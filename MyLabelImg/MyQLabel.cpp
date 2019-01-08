#include "MyQLabel.h"



MyQLabel::MyQLabel(QWidget *parent) : QLabel(parent),
x(-1), y(-1)
{
}

void MyQLabel::mouseMoveEvent(QMouseEvent *ev)
{
	this->x = ev->x();
	this->y = ev->y();
	emit Mouse_Moved();
}

void MyQLabel::mousePressEvent(QMouseEvent *ev)
{
	emit Mouse_Pressed();
}

void MyQLabel::leaveEvent(QEvent *)
{
	emit Mouse_Left();
}

int MyQLabel::getX()
{
	return x;
}

int MyQLabel::getY()
{
	return y;
}