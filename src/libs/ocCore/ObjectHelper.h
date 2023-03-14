#pragma once

#include <QMetaEnum>
#include <QMetaObject>
#include <QString>

class ObjectHelper
{
public:
    ObjectHelper() {;}
    ObjectHelper(QObject * obj);
    ObjectHelper(QObject * obj, const char * name);
    QString enumName(const int enumValue);
    int enumValue(const char * name);

private:
    QObject * mpObject=nullptr;
    const QMetaObject * cmpMetaObject=nullptr;
    QMetaEnum mMetaEnum;
};

