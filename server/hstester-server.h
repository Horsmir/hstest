#ifndef hstesterserver_H
#define hstesterserver_H

#include <QtCore/QDebug>
#include "testserver.h"
#include "testmanager.h"

class HstesterServer : public QObject
{
Q_OBJECT
public:
    HstesterServer(QObject *parent = 0);
    virtual ~HstesterServer();

private:
	TestServer *testServer;
	TestManager *testManager;
};

#endif // hstesterserver_H
