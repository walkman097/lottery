#include "mainwidget.h"
#include <QApplication>

int main(int argv, char **argc)
{
	QApplication app(argv, argc);
	
	MainWiget *widget = new MainWiget;
	widget->show();

	return app.exec();
}






