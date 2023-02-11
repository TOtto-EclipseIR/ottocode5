QT -= gui

TEMPLATE = lib
DEFINES += OCBASE_LIBRARY
CONFIG += c++17

include(../../version.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Key.cpp \
    KeyList.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyUidDMap.cpp \
    VersionInfo.cpp \
    ocBase.cpp

HEADERS += \
    Key.h \
    KeyList.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyUidDMap.h \
    List.h \
    Types.h \
    VersionInfo.h \
    ocBase_global.h \
    ocBase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
