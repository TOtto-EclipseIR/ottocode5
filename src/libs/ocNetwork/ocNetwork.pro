QT -= gui
QT *= network
TEMPLATE = lib
DEFINES += OCNETWORK_LIBRARY

message(======== in ocNetwork.pro)
include(../libs.pri)
include(../../useCore.pri)

SOURCES += \
    Network.cpp \
    QQUrl.cpp \
    ocNetwork.cpp

HEADERS += \
    Network.h \
    QQUrl.h \
    ocNetwork_global.h \
    ocNetwork.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
