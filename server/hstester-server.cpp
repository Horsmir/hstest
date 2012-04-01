#include "hstester-server.h"

HstesterServer::HstesterServer(QObject *parent):
	QObject(parent)
{
	testManager = new TestManager(this);
	QDir appDir(QCoreApplication::applicationDirPath());
	appDir.cdUp();
	appDir.cdUp();
	QString dataDirPath = appDir.absolutePath() + "/var/lib/hstest";
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
