#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T19:23:02
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

INCLUDEPATH += /usr/local/qwt-6.1.2/include

LIBS += -L/usr/local/qwt-6.1.2/lib -lqwt -Wl,-rpath,/usr/local/qwt-6.1.0/lib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = datacenter
TEMPLATE = app


SOURCES += main.cpp\
    form.cpp

HEADERS  += \
    form.h

FORMS    += \
    form.ui

RESOURCES += \
    dc.qrc
