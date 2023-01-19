#include "QtHelpViewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtHelpViewer w;
    w.show();
    return a.exec();
}
