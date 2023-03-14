QT -= gui
QT *= xml
QT *= sql
QT *= network
TEMPLATE = lib
DEFINES += OCXML_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useCore.pri)
include(../../useNetwork.pri)

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
