#pragma once

#include <QSharedDataPointer>

#include <QHostAddress>
#include <QMap>
#include <QString>

#include <Key.h>
#include <KeySeg.h>

#include "Network.h"

class UrlData;

class Url
{
public:
    Url(const QUrl &url);

public:
    UrlData * d();
    const UrlData * d() const;
    QString toString();

public:
    void set(const QUrl &url);

// --------------------- QSharedData implemenation -----------------------
public:
    Url();
    Url(const Url &);
    Url &operator=(const Url &);
    ~Url();
private:
    QSharedDataPointer<UrlData> data;
};

class UrlData : public QSharedData
{
public:
    Network::Scheme         dScheme;
    QString                 dUserName;
    QString                 dPassword;
    QHostAddress            dHostAddress;
    Network::Port           dPort;
    Key                     dPath;
    QString                 dFileName;
    QMap<KeySeg, QString>   dQueryMap;
};
