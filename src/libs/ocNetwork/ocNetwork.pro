QT -= gui
QT *= network
QT *= statemachine
TEMPLATE = lib
DEFINES += OCNETWORK_LIBRARY

message(======== in ocNetwork.pro)
include(../libs.pri)
include(../../useBase.pri)
include(../../useCore.pri)

SOURCES += \
    Channel.cpp \
    ChannelId.cpp \
    ChannelMachine.cpp \
    Network.cpp \
    NetworkError.cpp \
    Url.cpp \
    ocNetwork.cpp

HEADERS += \
    Channel.h \
    ChannelId.h \
    ChannelMachine.h \
    Network.h \
    NetworkError.h \
    Url.h \
    ocNetwork_global.h \
    ocNetwork.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

STATECHARTS +=
