#pragma once

#include <QString>
#include <QVariant>

#include "FunctionInfo.h"
#include "Key.h"
#include "Uid.h"

class ErrorInfo
{
public:
    ErrorInfo();

private:
    Uid mErrorUid;
    Key mErrorKey;
    QString mErrorString;
    QVariant mErrorData;
    FunctionInfo mFunctionInfo;
};

