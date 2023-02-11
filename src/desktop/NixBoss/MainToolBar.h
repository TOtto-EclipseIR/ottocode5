#pragma once

#include <QToolBar>

#include <QWidget>

class MainToolBar : public QToolBar
{
    Q_OBJECT
public:
    MainToolBar(QWidget *parent = nullptr);

public slots:
    void setup();
};

