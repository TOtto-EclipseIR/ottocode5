#include "ObjectHelper.h"


ObjectHelper::ObjectHelper(QObject *obj) : mpObject(obj) {;}

ObjectHelper::ObjectHelper(QObject *obj, const char * name)
    : mpObject(obj)
    , cmpMetaObject(obj->metaObject())
{
    const int tEnumIndex = cmpMetaObject->indexOfEnumerator(name);
    mMetaEnum = cmpMetaObject->enumerator(tEnumIndex);
}

QString ObjectHelper::enumName(const int enumValue)
{
    return mMetaEnum.valueToKey(enumValue);
}

int ObjectHelper::enumValue(const char *name)
{
    return mMetaEnum.keyToValue(name);
}
