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
	int	 getX();
	int  getY();

signals:
	void Mouse_Moved();
	void Mouse_Pressed();

private:
	int x;
	int y;
};

