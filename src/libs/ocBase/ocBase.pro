QT -= gui
TEMPLATE = lib
DEFINES += OCBASE_LIBRARY

include(../libs.pri)

SOURCES += \
    ErrorInfo.cpp \
    FunctionInfo.cpp \
    Key.cpp \
    KeyList.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyUidDMap.cpp \
    Uid.cpp \
    VersionInfo.cpp \
    ocBase.cpp

HEADERS += \
    DualMap.h \
    ErrorInfo.h \
    ErrorReturn.h \
    FunctionInfo.h \
    Key.h \
    KeyList.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyUidDMap.h \
    List.h \
    TypeDefs.h \
    Uid.h \
    VersionInfo.h \
    ocBase_global.h \
    ocBase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
