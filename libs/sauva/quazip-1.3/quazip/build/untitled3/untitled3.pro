QT -= gui

TEMPLATE = lib
CONFIG (staticlib): DEFINES+= QUAZIP_STATIC
LIBDIR += "/home/aquiles/Desktop/project/File_EXplorer/libs"
INCLUDEPATH += $${LIBDIR}
CONFIG += c++17
unix {
    LIB += -L$${LIBDIR} -lz
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../JlCompress.cpp \
    ../../qioapi.cpp \
    ../../quaadler32.cpp \
    ../../quachecksum32.cpp \
    ../../quacrc32.cpp \
    ../../quagzipfile.cpp \
    ../../quaziodevice.cpp \
    ../../quazip.cpp \
    ../../quazipdir.cpp \
    ../../quazipfile.cpp \
    ../../quazipfileinfo.cpp \
    ../../quazipnewinfo.cpp \
    ../../unzip.c \
    ../../zip.c

HEADERS += \
    ../../JlCompress.h \
    ../../ioapi.h \
    ../../minizip_crypt.h \
    ../../quaadler32.h \
    ../../quachecksum32.h \
    ../../quacrc32.h \
    ../../quagzipfile.h \
    ../../quaziodevice.h \
    ../../quazip.h \
    ../../quazip_global.h \
    ../../quazip_qt_compat.h \
    ../../quazipdir.h \
    ../../quazipfile.h \
    ../../quazipfileinfo.h \
    ../../quazipnewinfo.h \
    ../../unzip.h \
    ../../zconf.h \
    ../../zip.h \
    ../../zlib.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../QuaZipConfig.cmake.in \
    ../../quazip.pc.cmakein
