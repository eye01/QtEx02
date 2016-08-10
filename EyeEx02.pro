#-------------------------------------------------
#
# Project created by QtCreator 2016-08-01T01:15:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EyeEx02
TEMPLATE = app

 APPDATA_DIR = $$system(echo %APPDATA%) # should be %LOCALAPPDATA% as requested


SOURCES += main.cpp\
        widget.cpp \
    ClassA.cpp \
    ClassB.cpp

HEADERS  += widget.h \
    ClassA.h \
    ClassB.h

FORMS    += widget.ui \
    ClassA.ui \
    ClassB.ui

RESOURCES += \
    res/resource.qrc
