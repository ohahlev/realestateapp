TARGET = controller
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += network sql xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += homecontroller.h
SOURCES += homecontroller.cpp
HEADERS += contactcontroller.h
SOURCES += contactcontroller.cpp

HEADERS += bannercontroller.h
SOURCES += bannercontroller.cpp
HEADERS += featuredcontroller.h
SOURCES += featuredcontroller.cpp
HEADERS += servicecontroller.h
SOURCES += servicecontroller.cpp
