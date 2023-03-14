#include "QQUrl.h"

QQUrl::Scheme QQUrl::scheme() const
{
    return scheme(schemeName());
}

QString QQUrl::schemeName() const
{
    return QUrl::scheme();
}

// static
QQUrl::Scheme QQUrl::scheme(const QString s)
{
    if (false) ;
    else if ("http" == s) return Http;
    else if ("ftp" == s) return Ftp;
    else return $null;
}
