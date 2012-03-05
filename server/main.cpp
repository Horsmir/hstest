#include <QCoreApplication>
#include "hstester-server.h"

void demonize()
{
	if(QCoreApplication::arguments().contains("--no-daemon"))
		return;
	switch(fork())
	{
		case 0:
			break;
		case -1:
			exit(-1);
		default:
			exit(0);
	}
}

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
	HstesterServer foo;
	demonize();
	return app.exec();
}
