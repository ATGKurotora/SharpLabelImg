#include "MyLabelImg.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyLabelImg w;
	w.show();
	return a.exec();
}
