QT -= gui
TEMPLATE = lib
DEFINES += OCSQL_LIBRARY

include(../libs.pri)

SOURCES += \
    ocSql.cpp

HEADERS += \
    ocSql_global.h \
    ocSql.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
