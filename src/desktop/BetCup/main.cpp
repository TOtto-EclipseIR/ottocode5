#include "BetCupMain.h"
#include "version.h"
#include "../../version.h"
#include "../../libs/ocBase/VersionInfo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    VersionInfo tAppVersion(VER_MAJOR, VER_MINOR, VER_MICRO,
                            VER_MINI, 0, VER_STRING);
    QApplication a(argc, argv);
    a.setOrganizationName(VER_ORGNAME);
    a.setApplicationName(VER_APPNAME);
    a.setApplicationDisplayName(VER_APPNAME);
    a.setApplicationVersion(tAppVersion.toString());
    BetCupMain w;
    w.show();
    return a.exec();
}
