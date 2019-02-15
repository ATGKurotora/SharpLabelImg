#include "LabelButton.h"



LabelButton::LabelButton()
{}

LabelButton::LabelButton(QPushButton *button, int nbUsed, QString labelName) : 
	myButton(button), nbUsed(nbUsed), myLabelName(labelName)
{}

LabelButton::LabelButton(LabelButton const &other) : 
	myButton(other.myButton), nbUsed(other.nbUsed), myLabelName(other.myLabelName)
{}

LabelButton::~LabelButton()
{}

LabelButton	&LabelButton::operator=(LabelButton const &other)
{
	if (this != &other)
	{
		this->myButton = other.myButton;
		this->nbUsed = other.nbUsed;
		this->myLabelName = other.myLabelName;
	}

	return *this;
}

QPushButton	*LabelButton::getMyButton()
{
	return myButton;
}

int			LabelButton::getNbUsed()
{
	return nbUsed;
}

QString		LabelButton::getMyLabelName()
{
	return myLabelName;
}

void		LabelButton::incUsed()
{
	nbUsed = nbUsed + 1;
}

void		LabelButton::setMyButton(QPushButton *button)
{
	myButton = button;
}

void		LabelButton::setMyLabelName(QString labelName)
{
	myLabelName = labelName;
}