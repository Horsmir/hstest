#include "hstester-server.h"

HstesterServer::HstesterServer()
{
	testManager = new TestManager(this);
	testManager->readTestDbFromFile();
	testServer = new TestServer(testManager, this);
	
	if(!testServer->listen(QHostAddress::Any, 1605))
	{
		qDebug() << trUtf8("Unable to start the server: ") << testServer->errorString();
		return;
	}
	
	std::cout << "***Server started***" << std::endl;
	std::cout << "Address: " << testServer->serverAddress().toString().data() << std::endl;
	std::cout << "Port: " << testServer->serverPort() << std::endl;
}

HstesterServer::~HstesterServer()
{}

#include "hstester-server.moc"
