# file: {OttoCODE}./src/libs/useNetwork.pri

message(----------------In useNetwork.pri)

windows:LIBS *= -locNetwork5
linux:LIBS *= -locNetwork
INCLUDEPATH *= ../../libs/ocNetwork

message(LIBS = $$LIBS)
message(INCLUDEPATH = $$INCLUDEPATH)

