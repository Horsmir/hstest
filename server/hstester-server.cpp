#include "hstester-server.h"

HstesterServer::HstesterServer(QObject *parent):
	QObject(parent)
{
	testManager = new TestManager(this);
	QDir appDir(QCoreApplication::applicationDirPath());
	QString dataDirPath;
#ifdef Q_OS_LINUX
	appDir.cdUp();
	appDir.cdUp();
	dataDirPath = appDir.absolutePath() + "/var/lib/hstest";
#endif
#ifdef Q_OS_WIN32
	dataDirPath = appDir.absolutePath() + "/data";
#endif
	QDir dataDir(dataDirPath);
	if(!dataDir.exists())
		dataDir.mkpath(dataDirPath);
	testManager->setTestDir(dataDirPath);
	testManager->readTestDbFromFile();
	testManager->readStudentDbFromFile();
	testServer = new TestServer(testManager, this);
	
	if(!testServer->listen(QHostAddress::Any, 1605))
	{
		qDebug() << trUtf8("Unable to start the server: ") << testServer->errorString();
		return;
	}
}

HstesterServer::~HstesterServer()
{}

#include "hstester-server.moc"
