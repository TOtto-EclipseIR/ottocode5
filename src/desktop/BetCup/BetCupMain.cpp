#include "BetCupMain.h"

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QProgressBar>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QToolButton>
#include <QTimer>
#include <QWidget>

#include <ocExe/ActionManager.h>
#include <ocNetwork/Network.h>

BetCupMain::BetCupMain(QWidget *parent)
    : QMainWindow(parent)
    , mpMainGrid(new QGridLayout(this))
    , mpMainToolBar(new QToolBar("Main", this))
    , mpOpenUrlButton(new QToolButton(this))
    , mpProgressBar(new QProgressBar(this))
    , mpUrlEdit(new QLineEdit(this))
    , mpText(new QTextEdit(this))
    , mpActionManager(new ActionManager(this))
    , mpNetwork(new Network(this))
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpMainGrid);
    Q_CHECK_PTR(mpMainToolBar);
    Q_CHECK_PTR(mpOpenUrlButton);
    Q_CHECK_PTR(mpProgressBar);
    Q_CHECK_PTR(mpUrlEdit);
    Q_CHECK_PTR(mpText);
    Q_CHECK_PTR(mpNetwork);
    Q_CHECK_PTR(mpActionManager);
    setObjectName("BetCup:MainWindow");
    mpMainGrid->setObjectName("QGridLayout:Main");
    mpMainToolBar->setObjectName("QToolBar:Main");
    mpOpenUrlButton->setObjectName("QToolButton:OpenUrl");
    mpUrlEdit->setObjectName("QLineEdit:OpenUrl");
    mpText->setObjectName("QTextEdit:UrlText");
    QTimer::singleShot(200, this, &BetCupMain::initialize);
}

BetCupMain::~BetCupMain()
{
}

void BetCupMain::initialize()
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpNetwork);
    Q_CHECK_PTR(mpOpenUrlButton);
    mpOpenUrlButton->setText("Open URL");
    QAction * pOpenUrlAct = mpActionManager->add("OpenURL");
    mpOpenUrlButton->setDefaultAction(pOpenUrlAct);
    connect(mpNetwork, &Network::initialized,
            this, &BetCupMain::networkInitialized);
    connect(pOpenUrlAct, &QAction::triggered,
            this, &BetCupMain::openUrl);
    connect(mpUrlEdit, &QLineEdit::editingFinished,
            this, &BetCupMain::openUrlEntered);
    connect(mpNetwork, &Network::requestProgress,
            this, &BetCupMain::openUrlProgress);
    connect(mpNetwork, &Network::replyFinished,
            this, &BetCupMain::openUrlReplied);
    mpNetwork->initialize();
}

void BetCupMain::networkInitialized(const bool ok)
{
    qDebug() << Q_FUNC_INFO;
    if (ok)
        QTimer::singleShot(200, this, &BetCupMain::setup);
    else
        statusBar()->showMessage("Network Initialization failed");
}

void BetCupMain::setup()
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpMainGrid);
    Q_CHECK_PTR(mpUrlEdit);
    Q_CHECK_PTR(mpProgressBar);
    Q_CHECK_PTR(mpText);
    Q_CHECK_PTR(mpMainToolBar);
    Q_CHECK_PTR(mpOpenUrlButton);
    mpMainToolBar->addWidget(mpOpenUrlButton);
    mpUrlEdit->setReadOnly(true);
    mpUrlEdit->setEnabled(false);
    mpText->setEnabled(false);
    mpText->setMinimumSize(QSize(300, 300));
    QLabel * pUrlLabel = new QLabel("URL:");
    mpMainGrid->addWidget(pUrlLabel, 0, 0);
    mpMainGrid->addWidget(mpUrlEdit, 0, 1);
    mpMainGrid->addWidget(mpText, 1, 0, 1, 2);
    QWidget * pMainWidget = new QWidget(this);
    pMainWidget->setLayout(mpMainGrid);
    addToolBar(mpMainToolBar);
    mpProgressBar->setEnabled(false);
    statusBar()->addPermanentWidget(mpProgressBar, 100);
    setCentralWidget(pMainWidget);
}

void BetCupMain::openUrl()
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpUrlEdit);
    mpUrlEdit->setEnabled(true);
    mpUrlEdit->setReadOnly(false);
}

void BetCupMain::openUrlEntered()
{
    qDebug() << Q_FUNC_INFO;
    Q_CHECK_PTR(mpUrlEdit);
    mpUrlEdit->setReadOnly(true);
    mCurrentUrl = mpUrlEdit->text();
    QNetworkRequest * pRequest = new QNetworkRequest(mCurrentUrl);
    mpNetwork->requestGet(pRequest);
    statusBar()->showMessage("Requesting " + mCurrentUrl.toString());
}

void BetCupMain::openUrlProgress(const int count, const int limit, QNetworkRequest *request)
{
    Q_UNUSED(request);
    if (0 == count)
    {
        mpProgressBar->setEnabled(true);
        mpProgressBar->setMinimum(0);
        mpProgressBar->setMaximum(limit);
    }
    mpProgressBar->setValue(count);
}

void BetCupMain::openUrlReplied(QNetworkReply * reply, QNetworkRequest * request)
{
    Q_CHECK_PTR(mpText);
    Q_CHECK_PTR(reply);
    Q_CHECK_PTR(request);
    qDebug() << Q_FUNC_INFO << reply->url() << reply->bytesAvailable() << request->url();
    QByteArray mBytesReceived = reply->readAll();
    mpText->setPlainText(mBytesReceived);
    statusBar()->showMessage("Received " + mCurrentUrl.toString());
}

