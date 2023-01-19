#pragma once

#include "AbstractPageWidget.h"

class ViewPage : public AbstractPageWidget
{
    Q_OBJECT
public:
    ViewPage(const QString pageName, QWidget *parent = nullptr);

public:
    virtual QString name() const override;

private:
    QString mPageName;
};

