#pragma once

#include <QMetaEnum>
#include <QMetaObject>
#include <QString>

class ObjectHelper
{
public:
    ObjectHelper() {;}
    ObjectHelper(QObject * obj);

public:
    QString enumKey(const char *enumName, const int enumValue);
    int enumValue(const char *enumName, const char * key);
    template <typename T> static QString enumKey(const int enumValue)
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        return metaEnum.valueToKey(enumValue);
    }
    template <typename T> static int enumValue(const QString enumKey)
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<T>();
        return metaEnum.keyToValue((const char *)(enumKey.constData()));
    }

private:
    QMetaEnum metaEnum(const char * enumName);

private:
    const QObject * cmpObject=nullptr;
    const QMetaObject * cmpMetaObject=nullptr;
};

