#pragma once

#include "MyImg.h"
#include <QString>

class MyFile
{
public:
	MyFile();
	~MyFile();
	void	saveData(MyImg img);
	void	saveData(MyImg img, QString absolutePath);
	void	setAbsolutePath(QString absolutePath);
	QString	getAbsolutePath();
	
private:
	QString getStrLabData(MyImg img);
	QString	getStrData(MyImg img);

private:
	QString	_absolutePath;
};

