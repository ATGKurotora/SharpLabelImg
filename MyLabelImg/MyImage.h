#pragma once
#include <qfile.h>

typedef struct MyImage
{
	QFile		imgFile;
	QPixmap		imgPixmap;
};