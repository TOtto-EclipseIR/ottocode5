#pragma once

#include <QString>
#include <QVersionNumber>

#include "List.h"

class VersionInfo
{
public:
    enum Segment
    {
        $null = 0,
        Major,
        Minor,
        Branch,
        Release,
        Build,
        $size
    };

public:
    VersionInfo();
    VersionInfo(const int maj, const int min, const int bch=0, const QString &str=QString());
    VersionInfo(const int maj, const int min, const int bch, const int rel, const int bld=0, const QString &str=QString());

public:
    int major() const { return mSegments.at(Major); }
    int minor() const { return mSegments.at(Minor); }
    int branch() const { return mSegments.at(Branch); }
    int release() const { return mSegments.at(Release); }
    int build() const { return mSegments.at(Build); }
    QString string() const { return mString; }
    QString toString() const;
    QString dottedString() const;
    QVersionNumber toVersionNumber() const;

public:
    void major(const int i) { mSegments.at(Major) = i; }
    void minor(const int i) { mSegments.at(Minor) = i; }
    void branch(const int i) { mSegments.at(Branch) = i; }
    void release(const int i) { mSegments.at(Release) = i; }
    void build(const int i) { mSegments.at(Build) = i; }
    void string(const QString &s) { mString = s; }

private:
    QString releaseString() const;

private:
    List<int> mSegments;
    QString mString;
};

