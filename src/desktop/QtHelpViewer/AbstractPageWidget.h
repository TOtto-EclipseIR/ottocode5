#pragma once

#include <QWidget>

class AbstractPageWidget : public QWidget
{
    Q_OBJECT
public:
    enum PageType
    {
        $null = 0,
        BookList,
        Settings,
        Search,
        Results,
        ViewBase,
        $max
    };

public:
    explicit AbstractPageWidget(const PageType ptype, QWidget *parent = nullptr);

public:
    virtual QString name() const;

public slots:

signals:


private:
    PageType mPageType=$null;
};

