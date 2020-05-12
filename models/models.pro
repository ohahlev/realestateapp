TARGET = model
TEMPLATE = lib
CONFIG += shared c++14 x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/contactobject.h
HEADERS += contact.h
SOURCES += contact.cpp
HEADERS += sqlobjects/bannerobject.h

HEADERS += banner.h
SOURCES += banner.cpp
HEADERS += sqlobjects/featuredobject.h
HEADERS += featured.h
SOURCES += featured.cpp
HEADERS += sqlobjects/serviceobject.h
HEADERS += service.h
SOURCES += service.cpp
