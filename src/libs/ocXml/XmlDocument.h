#pragma once

#include <QDomDocument>

#include <QByteArray>
#include <QDomElement>
#include <QFileInfo>
#include <QStack>
#include <QString>
#include <QUrl>
#include <QSqlTableModel>
class QNetworkReply;

#include <Key.h>
#include <KeyList.h>
#include <KeyMap.h>

class XmlDocument : public QDomDocument
{
public:
    typedef KeyMap<QDomElement> KeyElementMap;

public:
    XmlDocument() {;}
    XmlDocument(const QDomDocument &other) : QDomDocument(other) {;}
    XmlDocument(const QFileInfo &fi)  { set(fi); }
    XmlDocument(QNetworkReply * reply) { set(reply); }
    XmlDocument(const QString &utfString) { set(utfString); }
    XmlDocument(const QByteArray &bytes) { set(bytes); }

public:
    QDomElement rootElement() const;
    QDomElement element(const Key &key) const;
    KeyElementMap keyElementMap() const;
    KeyList baseElementNames() const;
    QSqlTableModel extractSqlTableModel(const Key groupKey=Key());

public:
    void clear();
    void set(const QDomDocument &other);
    bool set(QNetworkReply * reply);
    bool set(const QFileInfo &fi);
    bool set(const QString &utfString);
    bool set(const QByteArray &bytes);
    void setBaseElement(const Key &groupKey);
    void enterElement(Key groupKey);
    bool leaveElement();

private:
    QDomDocument & it() { return *this; }
    QDomDocument it() const { return *this; }
    Key currentBaseElement() const;

private:
    QFileInfo mFileInfo;
    QString mUtfString;
    ParseResult mParseResult;
    QStack<Key> mBaseElementStack;
};

