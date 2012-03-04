#include <QtGui/QApplication>
#include "hstestcfg.h"


int main ( int argc, char** argv )
{
    QApplication app ( argc, argv );
    hstestcfg foo;
    foo.show();
    return app.exec();
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
