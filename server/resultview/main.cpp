#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLocale>
#include "resultview.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	
	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(), "/usr/share/qt/translations");
	app.installTranslator(&qtTranslator);
	
	ResultView foo;
	foo.show();
	return app.exec();
}