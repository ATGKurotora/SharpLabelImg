#pragma once

#include "MyImg.h"
#include <QString>

class MyFile
{
public:
	MyFile();
	~MyFile();
	void		saveMyImg(MyImg&);
	void		setMyImgFolderPath(QString);
	QString		getMyImgFolderPath();
	QStringList	getImgFileList(QString);
	
private:
	void		saveData(MyImg);
	void		checkAndCreateFolder();
	void		changeImgAndDataPath(MyImg&);
	QString		getStrLabData(MyImg);
	QString		getStrData(MyImg);
	QString		getImgExt(MyImg);
	int			getNumImg();

private:
	QString		myImgFolderPath;
};

