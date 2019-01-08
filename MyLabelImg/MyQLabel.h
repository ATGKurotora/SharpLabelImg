#pragma once
#include <QLabel>
#include <QMouseEvent>

class MyQLabel :
	public QLabel
{
	Q_OBJECT

public:
	explicit MyQLabel(QWidget *parent = 0);

	void mouseMoveEvent(QMouseEvent *ev);
	void mousePressEvent(QMouseEvent *ev);
	void leaveEvent(QEvent *);
	int	 getX();
	int  getY();

signals:
	void Mouse_Moved();
	void Mouse_Pressed();
	void Mouse_Left();

private:
	int x;
	int y;
};

