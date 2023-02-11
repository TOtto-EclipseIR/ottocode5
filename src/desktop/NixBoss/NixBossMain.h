#pragma once

#include <QMainWindow>

class QTabWidget;

class AbstractPage;
class MainToolBar;
class UsbPage;

class NixBossMain : public QMainWindow
{
    Q_OBJECT

public:
    NixBossMain(QWidget *parent = nullptr);
    ~NixBossMain();

public slots:
    void initialize();
    void parse();
    void setup();

private slots:
    void addPage(AbstractPage * pg);

signals:
    void constructed();
    void initialized();
    void parsed();
    void setupd();

private:
    MainToolBar * mpToolBar=nullptr;
    QTabWidget * mpMainTabWidget=nullptr;
    UsbPage * mpUsbPage=nullptr;
};
