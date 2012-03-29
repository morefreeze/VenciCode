#include "vencicode.h"
#include <QtGui/QApplication>

#include "VenciGame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VenciCode w;
    w.show();
    a.exec();
    //VenciGame vg = VenciGame(GameInfo(2,11,3));
    //VenciGame vg = VenciGame();
    //GameInfo gi = GameInfo(2,11,3);
    //vg.Start(&gi);
    //vg.Run();
}
