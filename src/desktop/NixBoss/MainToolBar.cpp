#include "MainToolBar.h"

MainToolBar::MainToolBar(QWidget *parent)
    : QToolBar("Main", parent)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("MainToolBar");
}

void MainToolBar::setup()
{

}
