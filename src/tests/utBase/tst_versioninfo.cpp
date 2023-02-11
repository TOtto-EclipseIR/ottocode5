#include <QtTest>

// add necessary includes here

class VersionInfo : public QObject
{
    Q_OBJECT

public:
    VersionInfo();
    ~VersionInfo();

private slots:
    void test_case1();

};

VersionInfo::VersionInfo()
{

}

VersionInfo::~VersionInfo()
{

}

void VersionInfo::test_case1()
{

}

QTEST_APPLESS_MAIN(VersionInfo)

#include "tst_versioninfo.moc"
