#pragma once

#include "MyImage.h"
#include <QString>

class MyFile
{
public:
	MyFile();
	~MyFile();
	void	saveData(MyImage img);
	void	saveData(MyImage img, QString absolutePath);
	void	setAbsolutePath(QString absolutePath);
	QString	getAbsolutePath();
	
private:
	QString	absolutePath;
};

