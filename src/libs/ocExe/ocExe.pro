QT -= gui
TEMPLATE = lib
DEFINES += OCEXE_LIBRARY

include(../libs.pri)
SOURCES += \
    ActionManager.cpp \
    ocExe.cpp

HEADERS += \
    ActionManager.h \
    ocExe_global.h \
    ocExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
