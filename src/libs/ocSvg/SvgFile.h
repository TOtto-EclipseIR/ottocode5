#pragma once

#include <QBitmap>
#include <QByteArray>
#include <QDomDocument>
#include <QFileInfo>
#include <QImage>
#include <QMap>
#include <QSize>
#include <QPixmap>
class QFile;

#include <QQSize.h>

class SvgFile
{
public:
    SvgFile();
    SvgFile(const QFileInfo &fileInfo) { set(fileInfo); }
    SvgFile(const QFile * file) { set(file); }
    SvgFile(const QByteArray &bytes) { set(bytes); }
    SvgFile(const QDomDocument &doc) { set(doc); }

public:
    QImage image(const QSize sz=QSize()) const;
    QPixmap pixmap(const QSize sz=QSize()) const;
    QBitmap bitmap(const QSize sz=QSize()) const;

public:
    void clear();
    void set(const QFileInfo &fileInfo);
    void set(const QFile * file);
    void set(const QByteArray &bytes);
    void set(const QDomDocument &doc);

private:
    QFileInfo mFileInfo;
    QFile * mpFile=nullptr;
    QByteArray mBytes;
    QDomDocument mDocument;
    QQSize mBaseSize;
    QMap<QSize, QImage> mSizeImageMap;
};

