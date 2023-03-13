# file: {Lancelot}./src/libs/useSql.pri

message(----------------In useSql.pri)

windows:LIBS *= -locSql5
linux:LIBS *= -locSql

#message(LIBS = $$LIBS)

