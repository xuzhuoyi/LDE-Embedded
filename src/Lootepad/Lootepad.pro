######################################################################
# Automatically generated by qmake (2.01a) ?? 8? 12 04:59:00 2014
######################################################################

QT += widgets

TEMPLATE = app

DESTDIR += ../../usr/bin

TARGET = lootepad
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h \
    textedittab.h \
    texteditor.h
FORMS += mainwindow.ui
SOURCES += main.cpp mainwindow.cpp \
    textedittab.cpp \
    texteditor.cpp

RESOURCES += \
    rc.qrc

# install
target.path = /usr/bin
INSTALLS += target

CONFIG += c++11
