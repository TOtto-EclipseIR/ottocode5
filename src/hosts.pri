# {Lancelot}./src/hosts.pri
message(----------------In ./src/hosts.pri)

OC_QMAKE_HOST=eagle
message(OC_QMAKE_HOST = $$OC_QMAKE_HOST)

include(./hosts/$$(OC_QMAKE_HOST).pri)


contains(OC_QMAKE_HOST, eagle) {
    message("Building on eagle!")
    OC_BASEDESTDIR = OTTOCODE_BASEBINDIR
}

message(OC_BASEDESTDIR = $${OC_BASEDESTDIR})
