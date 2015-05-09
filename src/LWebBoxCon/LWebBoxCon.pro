#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T15:00:22
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LWebBoxCon
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    customerqlabel.cpp

HEADERS  += widget.h \
    customerqlabel.h

FORMS    += widget.ui

RESOURCES += \
    lwbc.qrc
