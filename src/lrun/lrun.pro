#-------------------------------------------------
#
# Project created by QtCreator 2014-08-29T09:49:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR += ../../usr/bin

TARGET = lrun
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

# install
target.path = /usr/bin
INSTALLS += target

