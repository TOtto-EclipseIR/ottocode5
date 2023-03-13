# file: {OttoCODE}./src/libs/useBase.pri

message(----------------In useBase.pri)

windows:LIBS *= -locBase5
linux:LIBS *= -locBase
INCLUDEPATH *= ../../libs/ocBase

message(LIBS = $$LIBS)
message(INCLUDEPATH = $$INCLUDEPATH)

