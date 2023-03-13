QT += gui
TEMPLATE = lib
DEFINES += OCGUI_LIBRARY

include(../libs.pri)

SOURCES += \
    IconManager.cpp \
    IconManagerObject.cpp \
    ocGui.cpp

HEADERS += \
    IconManager.h \
    IconManagerObject.h \
    ocGui_global.h \
    ocGui.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
