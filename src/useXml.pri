# file: {QttoCODE}./src/libs/useXml.pri

message(----------------In useXml.pri)

windows:LIBS *= -locXml5
linux:LIBS *= -locXml

#message(LIBS = $$LIBS)

