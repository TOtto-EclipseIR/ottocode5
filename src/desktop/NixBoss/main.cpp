#include "NixBossMain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NixBossMain w;
    w.initialize();
    return a.exec();
}
