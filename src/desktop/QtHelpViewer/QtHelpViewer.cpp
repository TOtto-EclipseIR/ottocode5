#include "QtHelpViewer.h"

#include <QtDebug>
#include <QListWidget>
#include <QStackedWidget>
#include <QTimer>
#include <QToolBar>
#include <QVBoxLayout>

#include "AbstractPageWidget.h"
#include "BookListPage.h"
#include "SearchPage.h"
#include "SettingsPage.h"
#include "ResultsPage.h"

QtHelpViewer::QtHelpViewer(QWidget *parent)
    : QMainWindow(parent)
    , mpToolBar(new QToolBar(this))
    , mpPageSelector(new QListWidget(this))
    , mpStack(new QStackedWidget(this))
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpToolBar);
    Q_CHECK_PTR(mpPageSelector);
    Q_CHECK_PTR(mpStack);
    setObjectName("QHelpViewer");
    mpToolBar->setObjectName("QHelpViewer:ToolBar");
    mpPageSelector->setObjectName("QHelpViewer:PageSelector");
    mpStack->setObjectName("QHelpViewer:Stack");
    connect(this, &QtHelpViewer::constructed,
            this, &QtHelpViewer::initialize);
    connect(this, &QtHelpViewer::initialized,
            this, &QtHelpViewer::setup);
    connect(this, &QtHelpViewer::setuped,
            this, &QtHelpViewer::start);
    emit constructed();
}

QtHelpViewer::~QtHelpViewer() {;}

void QtHelpViewer::initialize()
{
    qDebug() << Q_FUNC_INFO;
    addPage(new BookListPage());
    addPage(new SettingsPage());
    addPage(new SearchPage());
    addPage(new ResultsPage());
    emit initialized();
}

void QtHelpViewer::setup()
{
    Q_CHECK_PTR(mpToolBar);
    Q_CHECK_PTR(mpPageSelector);
    Q_CHECK_PTR(mpStack);
    qDebug() << Q_FUNC_INFO;
    addToolBar(mpToolBar);
    mpStack->setMinimumSize(QSize(640, 640));
    QVBoxLayout * pVBox = new QVBoxLayout;
    pVBox->addWidget(mpPageSelector);
    pVBox->addWidget(mpStack);
    QWidget * pMainWidget = new QWidget;
    pMainWidget->setLayout(pVBox);
    setCentralWidget(pMainWidget);
    emit setuped();
}

void QtHelpViewer::start()
{
    qDebug() << Q_FUNC_INFO;

}

void QtHelpViewer::addPage(AbstractPageWidget *pPage)
{
    qDebug() << Q_FUNC_INFO << pPage->objectName();
    Q_CHECK_PTR(mpPageSelector);
    Q_CHECK_PTR(mpStack);
    mpPageList.append(pPage);
    mpPageSelector->addItem(pPage->name());
    mpStack->addWidget(pPage);
}
