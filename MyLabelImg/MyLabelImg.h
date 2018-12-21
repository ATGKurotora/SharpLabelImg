#pragma once

#include "MyImg.h"
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

private:
	Ui::MyLabelImgClass ui;
	int					imgPtr;
	QVector<MyImg>		listImg;
	MyImg				myImage;

private:
	void				refreshImg();
};
