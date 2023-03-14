# file: {OttoCODE}./src/libs/useCore.pri

message(----------------In useCore.pri)

windows:LIBS *= -locCore5
linux:LIBS *= -locCore
INCLUDEPATH *= ../../libs/ocCore

message(LIBS = $$LIBS)
message(INCLUDEPATH = $$INCLUDEPATH)

