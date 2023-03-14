#include "Network.h"

#include <QMetaEnum>

#include <ObjectHelper.h>

QString Network::errorName(const Error value)
{
    ObjectHelper tOH(this, "Error");
    return tOH.enumName(value);
}

Network::Error Network::errorValue(const char * name)
{
    ObjectHelper tOH(this, "Error");
    return Network::Error(tOH.enumValue(name));
}

