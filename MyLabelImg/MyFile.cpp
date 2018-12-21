#include "MyFile.h"



MyFile::MyFile()
{
}

MyFile::~MyFile()
{
}

void	MyFile::saveData(MyImage img)
{
	if (!absolutePath.isEmpty())
	{
		QFile myFile(absolutePath);

		myFile.wr
	}
}