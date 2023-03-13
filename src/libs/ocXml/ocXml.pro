QT -= gui
QT *= xml
TEMPLATE = lib
DEFINES += OCXML_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    HtmlPage.cpp \
    XmlDocument.cpp \
    ocXml.cpp \


HEADERS += \
    HtmlPage.h \
    XmlDocument.h \
    ocXml_global.h \
    ocXml.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
