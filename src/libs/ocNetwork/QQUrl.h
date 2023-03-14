#pragma once

#include <QUrl>
#include <QUrlQuery>

class QQUrl : public QUrl
{
public:
    enum Scheme
    {
        $null = 0,
        Http,
        Ftp,
        $max
    };

public:
    QQUrl();
    QQUrl(const QUrl &other) : QUrl(other) {;}
    QQUrl(const QString &url, QUrl::ParsingMode parsingMode = TolerantMode);

public:
    virtual Scheme scheme() const;
    QString schemeName() const;

private:
    static Scheme scheme(const QString s);

private:
    QUrlQuery mQuery;
};

