#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include "hstester-client.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
	app.setApplicationName("Hs Test");
	app.setApplicationVersion("0.3");
	
	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(), "/usr/share/qt/translations");
	app.installTranslator(&qtTranslator);
	
    MainWindow mw;
    mw.show();
    return app.exec();
}
