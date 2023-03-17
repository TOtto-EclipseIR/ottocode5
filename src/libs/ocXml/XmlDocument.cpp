#include "XmlDocument.h"

#include <QtDebug>
#include <QNetworkReply>

#include <Network.h>
#include <NetworkError.h>
#include <ObjectHelper.h>

void XmlDocument::clear()
{
    qDebug() << Q_FUNC_INFO;
}

void XmlDocument::set(const QDomDocument &other)
{
    qDebug() << Q_FUNC_INFO;
    it() = other;
}

bool XmlDocument::set(QNetworkReply * reply)
{
    qDebug() << Q_FUNC_INFO << reply->url() << reply->error();
    NetworkError tNE(reply->error());
    if (tNE)
        mParseResult.errorMessage = tNE.codeKey();
    else
        set(reply->readAll());
    return bool(mParseResult);
}

bool XmlDocument::set(const QFileInfo &fi)
{
    qDebug() << Q_FUNC_INFO << fi;
    bool result = false;
    mFileInfo = fi;
    QFile * pFile = new QFile(mFileInfo.filePath());
    result = pFile->open(QIODevice::ReadOnly | QIODevice::Text);
    if (result)
        set(pFile->readAll());
    else
        mParseResult.errorMessage = pFile->errorString();
    pFile->deleteLater();
    return bool(mParseResult);
}

bool XmlDocument::set(const QByteArray &bytes)
{
    qDebug() << Q_FUNC_INFO;
    return set(QString(bytes));
}

bool XmlDocument::set(const QString &utfString)
{
    qDebug() << Q_FUNC_INFO;
    mUtfString = utfString;
    mParseResult = setContent(mUtfString);
    return bool(mParseResult);
}

void XmlDocument::setBaseElement(const Key &groupKey)
{
    qDebug() << Q_FUNC_INFO;
    mBaseElementStack.push(groupKey);
}

void XmlDocument::enterElement(Key groupKey)
{
    qDebug() << Q_FUNC_INFO;
    Key tKey = mBaseElementStack.top();
    tKey += groupKey;
    mBaseElementStack.push(tKey);
}

bool XmlDocument::leaveElement()
{
    qDebug() << Q_FUNC_INFO;
    bool result = ! mBaseElementStack.isEmpty();
    if (result) mBaseElementStack.pop();
    return result;
}

Key XmlDocument::currentBaseElement() const
{
    qDebug() << Q_FUNC_INFO;
    return mBaseElementStack.isEmpty() ? Key() : mBaseElementStack.top();
}
