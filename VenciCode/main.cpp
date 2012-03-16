#include "vencicode.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VenciCode w;
    w.show();
    return a.exec();
}
