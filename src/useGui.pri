# file: {OttoCODE}./src/libs/useGui.pri

message(----------------In useGui.pri)

windows:LIBS *= -locGui5
linux:LIBS *= -locGui

#message(LIBS = $$LIBS)

