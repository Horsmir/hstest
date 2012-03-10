#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include "hstestcfg.h"


int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(), "/usr/share/qt/translations");
	app.installTranslator(&qtTranslator);

	hstestcfg foo;
	foo.show();
	return app.exec();
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs off; tab-width 4; 
