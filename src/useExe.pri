# file: {OttoCODE}./src/libs/useExe.pri

message(----------------In useExe.pri)

windows:LIBS *= -locExe5
linux:LIBS *= -locExe

#message(LIBS = $$LIBS)

