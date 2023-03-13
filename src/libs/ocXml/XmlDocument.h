#pragma once

#include <QDomDocument>

#include <QByteArray>
#include <QFileInfo>
#include <QStack>
#include <QString>
#include <QUrl>

#include <Key.h>

class XmlDocument : public QDomDocument
{
public:
    XmlDocument();
    XmlDocument(const QDomDocument &other);
    XmlDocument(const QFileInfo &fi);
    XmlDocument(const QUrl &url);
    XmlDocument(const QByteArray &bytes);
    XmlDocument(const QString &name);

public:
    void clear();
    void set(const QDomDocument &other);
    void set(const QUrl &url);
    void set(const QFileInfo &fi);
    void set(const QByteArray &bytes);
    void setBaseElement(const Key &groupName);
    bool enterElement(const Key &groupName);
    bool leaveElement();

private:
    QFileInfo mFileInfo;
    QByteArray mBytes;
    QStack<Key> mBaseNamesStack;
};

