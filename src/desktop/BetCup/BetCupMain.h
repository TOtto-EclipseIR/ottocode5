#pragma once

#include <QMainWindow>

#include <QUrl>

class QGridLayout;
class QLineEdit;
class QNetworkReply;
class QNetworkRequest;
class QProgressBar;
class QTextEdit;
class QToolBar;
class QToolButton;

class ActionManager;
class Network;

class BetCupMain : public QMainWindow
{
    Q_OBJECT

public:
    BetCupMain(QWidget *parent = nullptr);
    ~BetCupMain();

public:

private slots:
    void initialize();
    void networkInitialized(const bool ok);

    void setup();
    void openUrl();
    void openUrlEntered();
    void openUrlReplied(QNetworkReply * reply, QNetworkRequest *request);

private:
    QGridLayout * mpMainGrid=nullptr;
    QToolBar * mpMainToolBar=nullptr;
    QToolButton * mpOpenUrlButton=nullptr;
    QProgressBar * mpProgressBar=nullptr;
    QLineEdit * mpUrlEdit=nullptr;
    QTextEdit * mpText=nullptr;
    ActionManager * mpActionManager=nullptr;
    Network * mpNetwork=nullptr;
    QUrl mCurrentUrl;
};
