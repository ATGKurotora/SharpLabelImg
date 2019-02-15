#pragma once
#include <QPushButton>

class LabelButton
{
public:
	LabelButton();
	LabelButton(QPushButton *, int, QString);
	LabelButton(LabelButton const &);
	~LabelButton();
	LabelButton	&operator=(LabelButton const &);
	QPushButton *getMyButton();
	int			getNbUsed();
	QString		getMyLabelName();
	void		incUsed();
	void		setMyButton(QPushButton *);
	void		setMyLabelName(QString);

private:
	QPushButton	*myButton;
	int			nbUsed;
	QString		myLabelName;
};

