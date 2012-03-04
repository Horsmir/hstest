#include <QCoreApplication>
#include "hstester-server.h"


int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    HstesterServer foo;
    return app.exec();
}
