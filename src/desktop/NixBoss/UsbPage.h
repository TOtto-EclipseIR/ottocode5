#pragma once

#include "AbstractPage.h"

class UsbPage : public AbstractPage
{
    Q_OBJECT
public:
    UsbPage(QWidget *parent = nullptr);

    // AbstractPage interface
public slots:
    void initialize();
    void parse();
    void setup();
};

