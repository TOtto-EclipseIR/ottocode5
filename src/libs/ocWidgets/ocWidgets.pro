QT += widgets
TEMPLATE = lib
DEFINES += OCWIDGETS_LIBRARY

include(../libs.pri)

SOURCES += \
    ocWidgets.cpp

HEADERS += \
    ocWidgets_global.h \
    ocWidgets.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
