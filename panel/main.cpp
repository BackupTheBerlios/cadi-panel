#include <QtGui/QApplication>
#include "cadi.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cadi w;
    w.show();
    return a.exec();
}
