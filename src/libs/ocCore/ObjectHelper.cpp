#include "ObjectHelper.h"


ObjectHelper::ObjectHelper(QObject *obj)
    : cmpObject(obj)
    , cmpMetaObject(cmpObject->metaObject())
{
}

QString ObjectHelper::enumKey(const char *enumName, const int enumValue)
{
    return metaEnum(enumName).valueToKey(enumValue);
}

int ObjectHelper::enumValue(const char *enumName, const char *key)
{
    return metaEnum(enumName).keyToValue(key);
}

QMetaEnum ObjectHelper::metaEnum(const char *enumName)
{
    QMetaEnum result;
    const int tEnumIndex = cmpMetaObject->indexOfEnumerator(enumName);
    if (tEnumIndex >= 0)
        result = cmpMetaObject->enumerator(tEnumIndex);
    return result;
}

