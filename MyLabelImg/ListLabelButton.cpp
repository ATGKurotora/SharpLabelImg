#include "ListLabelButton.h"

ListLabelButton::ListLabelButton()
{
	myColor[0] = Qt::red;
	myColor[1] = Qt::green;
	myColor[2] = Qt::blue;
	myColor[3] = Qt::white;
	myColor[4] = Qt::black;
	myColor[5] = Qt::cyan;
	myColor[6] = Qt::magenta;
	myColor[7] = Qt::yellow;
	myColor[8] = Qt::gray;
	myColor[9] = QColor(255, 160, 0);
}

ListLabelButton::~ListLabelButton()
{
}

QVector<LabelButton>	ListLabelButton::getMyListButton()
{
	return myListButton;
}

void					ListLabelButton::addLabelButton(QPushButton *button, QString labelName, int pos)
{
	button->setText(labelName);
	LabelButton	newLabelButton(button, 0, labelName);
	
	if (myListButton.size() < 10)
		myListButton.append(newLabelButton);
	else
	{
		LabelButton labelButton = myListButton[pos];
		myListButton[pos] = newLabelButton;
		delete labelButton.getMyButton();
	}
}

void					ListLabelButton::incButtonLabel(QString labelName)
{
	int i = 0;
	
	while (i < myListButton.size())
	{
		if (myListButton[i].getMyLabelName() == labelName)
			myListButton[i].incUsed();
		i++;
	}
}

int						ListLabelButton::getPosNewButton()
{
	if (myListButton.size() < 10)
		return myListButton.size();
	else
	{
		int i = 0;
		int saveI = 0;
		int minNb = myListButton[i].getNbUsed();

		for each (LabelButton labelButton in myListButton)
		{
			if (labelButton.getNbUsed() < minNb)
			{
				saveI = i;
				minNb = labelButton.getNbUsed();
			}
			i++;
		}
		return saveI;
	}
}

int						ListLabelButton::getPosButton(QString labelName)
{
	int i = 0;

	while (i < myListButton.size())
	{
		if (labelName == myListButton[i].getMyLabelName())
			return i;
		i++;
	}
	return -1;
}

QColor					ListLabelButton::getButtonColor(int pos)
{
	return myColor[pos];
}

QString					ListLabelButton::getButtonColorStr(int pos)
{
	QString	color;

	color = "border:3px solid #";
	if (myColor[pos].red() < 16)
		color += "0";
	color += QString::number(myColor[pos].red(), 16);
	if (myColor[pos].green() < 16)
		color += "0";
	color += QString::number(myColor[pos].green(), 16);
	if (myColor[pos].blue() < 16)
		color += "0";
	color += QString::number(myColor[pos].blue(), 16);
	if (myColor[pos].alpha() < 16)
		color += "0";

	return color;
}

bool					ListLabelButton::isNotInList(QString labelName)
{
	int i = 0;
	QString labelInList;

	while (i < myListButton.size())
	{
		labelInList = myListButton[i].getMyLabelName();
		if (labelName.toUpper() == labelInList.toUpper())
			return false;
		i++;
	}
	return true;
}