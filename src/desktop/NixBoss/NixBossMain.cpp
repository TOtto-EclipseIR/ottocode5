#include "NixBossMain.h"

#include <QtDebug>
#include <QTabWidget>

#include "AbstractPage.h"
#include "MainToolBar.h"
#include "UsbPage.h"

NixBossMain::NixBossMain(QWidget *parent)
    : QMainWindow(parent)
    , mpToolBar(new MainToolBar(this))
    , mpMainTabWidget(new QTabWidget)
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpMainTabWidget);
    setObjectName("mpMainTabWidget");
    mpMainTabWidget->setObjectName("QTabWidget:Main");
    emit constructed();
}

NixBossMain::~NixBossMain()
{
    qDebug() << Q_FUNC_INFO;
    delete mpMainTabWidget;
}

void NixBossMain::initialize()
{
    qDebug() << Q_FUNC_INFO;
    mpUsbPage = new UsbPage(this);
    mpUsbPage->initialize();
    addPage(mpUsbPage);
    connect(this, &NixBossMain::initialized, this, &NixBossMain::parse);
    connect(this, &NixBossMain::parsed, this, &NixBossMain::setup);
    emit initialized();
}

void NixBossMain::parse()
{
    qDebug() << Q_FUNC_INFO;
    mpUsbPage->parse();

}

void NixBossMain::setup()
{
    qDebug() << Q_FUNC_INFO;
    addToolBar(mpToolBar);
    mpToolBar->setup();
    mpUsbPage->setup();

    show();
}

void NixBossMain::addPage(AbstractPage *pg)
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpMainTabWidget);
    Q_CHECK_PTR(pg);
    mpMainTabWidget->addTab(pg, pg->icon(), pg->title());

}
