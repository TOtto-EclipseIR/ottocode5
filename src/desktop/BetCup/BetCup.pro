QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(../desktop.pri)
include(../../useBase.pri)
include(../../useGui.pri)
include(../../useExe.pri)
include(../../useSql.pri)
include(../../useXml.pri)


SOURCES += \
    main.cpp \
    BetCupMain.cpp

HEADERS += \
    ../../version.h \
    BetCupMain.h \
    version.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
