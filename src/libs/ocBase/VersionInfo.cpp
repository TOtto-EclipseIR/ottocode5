#include "VersionInfo.h"

VersionInfo::VersionInfo()
    : mSegments($size, 0)
{
    ;
}

VersionInfo::VersionInfo(const int maj, const int min, const int bch, const QString &str)
    : mSegments($size, 0)
{
    major(maj), minor(min), branch(bch), string(str);
}

VersionInfo::VersionInfo(const int maj, const int min, const int bch, const int rel, const int bld, const QString &str)
    : mSegments($size, 0)
{
    major(maj), minor(min), branch(bch), release(rel), build(bld), string(str);
}

QString VersionInfo::toString() const
{
    QString result = QString("v%1").arg(major());
    if (minor()) result += QString(".%1").arg(minor());
    if (release()) result += releaseString();
    if (branch()) result += QString("+%1").arg(branch(), 4, QChar('0'));
    return result;
}

QString VersionInfo::dottedString() const
{
    return toVersionNumber().toString();
}

QVersionNumber VersionInfo::toVersionNumber() const
{
    return QVersionNumber(mSegments.toQList());
}

QString VersionInfo::releaseString() const
{
    QString result;
    const int i = release();
    if (i > 0 && i <= 26) result = QChar('@' + i);
    else if (i >= 0xA0 && i <= 0xAF) result = QString("-Alpha%1").arg(i - 0xA0);
    else if (i >= 0xB0 && i <= 0xBF) result = QString("-Beta%1").arg(i - 0xB0);
    else if (i >= 0xC0 && i <= 0xCF) result = QString("-RC%1").arg(i - 0xC0);
    else if (i >= 0xD0 && i <= 0xDF) result = QString("-Delta%1").arg(i - 0xD0);
    else if (i >= 0xE0 && i <= 0xEF) result = QString("-Echo%1").arg(i - 0xE0);
    else if (i >= 0xF0 && i <= 0xFF) result = QString("-Final%1").arg(i - 0xF0);
    return result;
}

