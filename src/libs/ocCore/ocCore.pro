QT -= gui
TEMPLATE = lib
DEFINES += OCCORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    ObjectHelper.cpp \
    QQSize.cpp \
    ocCore.cpp

HEADERS += \
    ObjectHelper.h \
    QQSize.h \
    ocCore_global.h \
    ocCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
