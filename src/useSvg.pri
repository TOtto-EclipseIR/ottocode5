# file: {QttoCODE}./src/libs/useSvg.pri

message(----------------In useSvg.pri)

windows:LIBS *= -locSvg5
linux:LIBS *= -locSvg

#message(LIBS = $$LIBS)

