#pragma once

#include <QMainWindow>

class QListWidget;
class QStackedWidget;
class QToolBar;

class AbstractPageWidget;

class QtHelpViewer : public QMainWindow
{
    Q_OBJECT
public:
    QtHelpViewer(QWidget *parent = nullptr);
    ~QtHelpViewer();

private slots:
    void initialize();
    void setup();
    void start();

    void loadBookList() {;}
    void addPage(AbstractPageWidget *pPage);

signals:
    void constructed();
    void initialized();
    void setuped();
    void started();

private:
    QToolBar * mpToolBar=nullptr;
    QListWidget * mpPageSelector=nullptr;
    QStackedWidget * mpStack=nullptr;
    QList<AbstractPageWidget *> mpPageList;
};
