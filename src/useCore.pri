# file: {OttoCODE}./src/libs/useCore.pri

message(----------------In useCore.pri)

windows:LIBS *= -locqCore5
linux:LIBS *= -locqCore

#message(LIBS = $$LIBS)

