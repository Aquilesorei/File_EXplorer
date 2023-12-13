cmake_minimum_required(VERSION 3.20)
project(File_Explorer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(Qt6_DIR "/home/aquiles/Qt/6.5.1/gcc_64/lib/cmake/Qt6")
set(CMAKE_PREFIX_PATH "/home/aquiles/Qt/6.5.1/gcc_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
      #  Dbus
        PrintSupport
        Network
        Concurrent
        Core5Compat
        REQUIRED)
        
        
   add_executable(File_Explorer main.cpp components/CentralWidget.cpp components/CentralWidget.h components/Actions.cpp components/Actions.h components/Analysa.cpp components/Analysa.h components/Archiva.cpp components/Archiva.h MainWindow.cpp MainWindow.h FileTransfertHome.cpp   FileTransfertHome.h components/Welcome.cpp components/Welcome.h components/leftWidget.cpp
           components/leftWidget.h components/searchbar.cpp components/searchbar.h
           components/tabwidget.cpp components/tabwidget.h
           ${CMAKE_CURRENT_SOURCE_DIR}/Views/DirView.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Views/DirView.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Views/leftView.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/Views/leftView.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/BackgroundContextMenu.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/BackgroundContextMenu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/FileD.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/FileD.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/FolderD.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/FolderD.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/MultiD.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/MultiD.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/Progressa.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/Progressa.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/SortD.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/SortD.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/backD.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/backD.h  
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/openWith.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/Dialogs/openWith.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/FileContextMenu.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/FileContextMenu.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/MultiContextMenu.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/MultiContextMenu.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/folderContextMenu.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/menu/folderContextMenu.h 
    ${CMAKE_CURRENT_SOURCE_DIR}/toolbars/toolbarfichiers.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/toolbars/toolbarfichiers.h 
      
      ${CMAKE_CURRENT_SOURCE_DIR}/libs/QRoundProgressBar/QRoundProgressBar.cpp
       ${CMAKE_CURRENT_SOURCE_DIR}/libs/QRoundProgressBar/QRoundProgressBar.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/JlCompress.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/ioapi.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/minizip_crypt.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quaadler32.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quachecksum32.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quacrc32.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quagzipfile.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quaziodevice.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazip.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazip_global.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazip_qt_compat.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipdir.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipfile.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipfileinfo.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipnewinfo.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/unzip.h
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/zip.h


           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/unzip.c
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/zip.c
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/JlCompress.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/qioapi.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quaadler32.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quachecksum32.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quacrc32.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quagzipfile.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quaziodevice.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazip.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipdir.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipfile.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipfileinfo.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/libs/quazip/quazipnewinfo.cpp)
link_directories(${CMAKE_BINARY_DIR}/)



 target_link_libraries(File_Explorer
         #PRIVATE Qt6::Dbus
        PRIVATE Qt6::Concurrent
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt6::Network
         Qt6::Core5Compat
         libz.a libz.so libz.so.1

        )


    
     
 

    
  


   
     
 
 
      
  
    
    
    



