#pragma once

#include "MyFile.h"
#include "MyQLabel.h"
#include "ListLabelButton.h"
#include <QtWidgets/QMainWindow>
#include <QDir>
#include <QSignalMapper>
#include "ui_MyLabelImg.h"

class MyLabelImg : public QMainWindow
{
	Q_OBJECT

public:
	MyLabelImg(QWidget *parent = Q_NULLPTR);
	virtual ~MyLabelImg();

public slots:
	void				browseImg();
	void				previousImg();
	void				nextImg();
	void				saveImgButton();
	void				saveLabel();

private slots:
	void				MouseMoved();
	void				MousePressed();
	void				selectCurrentLabel(QString);

private:
	Ui::MyLabelImgClass ui;
	int					imgPtr;
	QString				myCurrentLabel;
	QColor				myCurrentColor;
	QVector<MyImg>		listImg;
	MyFile				myFile;
	ListLabelButton		myListLabelButton;
	QSignalMapper		*mySignalMapper;

private:
	void				saveImg();
	void				refreshImg();
	void				refreshListLabelButton();
	void				clearLayout(QLayout *);
	xyInt				getTrueCoordinate(xyInt);
};
