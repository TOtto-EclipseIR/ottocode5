QT += gui
QT *= xml

TEMPLATE = lib
DEFINES += OCSVG_LIBRARY

include(../libs.pri)
include(../../useCore.pri)

SOURCES += \
    SvgFile.cpp \
    ocSvg.cpp

HEADERS += \
    SvgFile.h \
    ocSvg_global.h \
    ocSvg.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
