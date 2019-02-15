#pragma once
#include <QColor>
#include <QVector>
#include "LabelButton.h"

class ListLabelButton
{
public:
	ListLabelButton();
	~ListLabelButton();
	QVector<LabelButton>	getMyListButton();
	void					addLabelButton(QPushButton*, QString, int);
	void					incButtonLabel(QString);
	int						getPosNewButton();
	int						getPosButton(QString);
	QColor					getButtonColor(int);
	QString					getButtonColorStr(int);
	bool					isNotInList(QString);

private:
	QVector<LabelButton>	myListButton;
	QColor					myColor[10];
};

