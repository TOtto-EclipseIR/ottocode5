#include "FunctionInfo.h"

#include <QFileInfo>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>

class FunctionInfoData : public QSharedData
{
public:
    QString dQFuncInfo;
    QFileInfo dFileInfo;
    int dFunctionLine;
    int dLineNumber;
    QVariant dReturnValue;
    QVariantList dArgumentValues;
    QStringList dArgumentNames;
};

FunctionInfo::FunctionInfo() : data(new FunctionInfoData) {;}
FunctionInfo::FunctionInfo(const FunctionInfo &rhs) : data{rhs.data} {;}
FunctionInfo::~FunctionInfo() {;}

FunctionInfo &FunctionInfo::operator=(const FunctionInfo &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

