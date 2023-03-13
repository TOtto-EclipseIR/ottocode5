#include "IconManagerObject.h"

#include <QGuiApplication>

IconManagerObject::IconManagerObject()
    : QObject{qApp}
{
    setObjectName("IconManagerObject");
}
