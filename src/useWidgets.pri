# file: {OttoCODE}./src/libs/useWidgets.pri

message(----------------In useWidgets.pri)

windows:LIBS *= -locqWidgets5
linux:LIBS *= -locqWidgets

#message(LIBS = $$LIBS)

