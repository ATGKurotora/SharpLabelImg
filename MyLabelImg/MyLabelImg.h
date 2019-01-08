#pragma once

#include "MyImg.h"
#include "MyQLabel.h"
#include <QtWidgets/QMainWindow>
#include <QDir>
#include "ui_MyLabelImg.h"

class MyLabelImg : public QMainWindow
{
	Q_OBJECT

public:
	MyLabelImg(QWidget *parent = Q_NULLPTR);
	virtual ~MyLabelImg();

public slots:
	void	browseImg();
	void	previousImg();
	void	nextImg();
	void	saveImg();
	void	saveLabel();

private slots:
	void	MouseMoved();
	void	MousePressed();
	void	MouseLeft();

private:
	Ui::MyLabelImgClass ui;
	int					imgPtr;
	QVector<MyImg>		listImg;
	MyImg				myImage;
	QString				myLabel;

private:
	void				refreshImg();
};
