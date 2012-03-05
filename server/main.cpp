#include <errno.h>
#include <QCoreApplication>
#include "hstester-server.h"

void daemonize()
{
    if(QCoreApplication::arguments().contains("--no-daemon"))
        return;
    
    switch (fork())
    {
        case 0:  break;
        case -1: exit(errno);
        default: exit(0);
    }
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    
    HstesterServer server;
    
    daemonize();
    
    return app.exec();
}