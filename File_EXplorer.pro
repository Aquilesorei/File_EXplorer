
QT += widgets
QT += gui
QT += concurrent
QT += dbus
QT += core5compat
QT += network
#QT += scxml
DEFINES += QUAZIP_STATIC
SOURCES += \
    Achille.cpp \
    Actions.cpp \
    Analysa.cpp \
    Archiva.cpp \
    FenPrincipale.cpp \
    FileTransfertHome.cpp \
    Views/DirView.cpp \
    Views/leftView.cpp \
    Welcome.cpp \
    disks.cpp \
    leftWidget.cpp \
    main.cpp \
    menu/BackgroundContextMenu.cpp \
    menu/Dialogs/FileD.cpp \
    menu/Dialogs/FolderD.cpp \
    menu/Dialogs/MultiD.cpp \
    menu/Dialogs/Progressa.cpp \
    menu/Dialogs/SortD.cpp \
    menu/Dialogs/backD.cpp \
    menu/Dialogs/openWith.cpp \
    menu/FileContextMenu.cpp \
    menu/MultiContextMenu.cpp \
    menu/folderContextMenu.cpp \
    searchbar.cpp \
    tabwidget.cpp \
    toolbars/toolbarfichiers.cpp \
    udisks2.cpp
    \actions.cpp


HEADERS += \
    Achille.h \
    Actions.h \
    Analysa.h \
    Archiva.h \
    FenPrincipale.h \
    FileTransfertHome.h \
    Views/DirView.h \
    Views/leftView.h \
    Welcome.h \
    disks.h \
    leftWidget.h \
    menu/BackgroundContextMenu.h \
    menu/Dialogs/FileD.h \
    menu/Dialogs/FolderD.h \
    menu/Dialogs/MultiD.h \
    menu/Dialogs/Progressa.h \
    menu/Dialogs/SortD.h \
    menu/Dialogs/backD.h \
    menu/Dialogs/openWith.h \
    menu/FileContextMenu.h \
    menu/MultiContextMenu.h \
    menu/folderContextMenu.h \
    searchbar.h \
    tabwidget.h \
    toolbars/toolbarfichiers.h \
    udisks2.h
    \actions.h


QT += core

DISTFILES += \
    menu/Dialogs/PyGetFolderSize.py


INCLUDEPATH += -I usr/include/python3.9
ROUNDPROGRESSBAR = "/home/aquiles/Documents/QTCreator/File_EXplorer/libs/QRoundProgressBar"
QUAZIPCODEDIR = "/home/aquiles/Documents/QTCreator/File_EXplorer/libs/quazip"
ZLIBCODEDIR = "/home/aquiles/Desktop/sauva/zlib"
unix {
       LIBS += -L$${ZLIBCODEDIR} -lz
      # LIBS += -L$${CODA} -lz
   }
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS +=  $${QUAZIPCODEDIR}/*.h
SOURCES += $${QUAZIPCODEDIR}/*.cpp
SOURCES += $${QUAZIPCODEDIR}/*.c

INCLUDEPATH += $${ROUNDPROGRESSBAR}
HEADERS +=  $${ROUNDPROGRESSBAR}/*.h
SOURCES += $${ROUNDPROGRESSBAR}/*.cpp
