#include <QtGui/QApplication>
#include "hstest.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    hstest foo;
    foo.show();
    return app.exec();
}
