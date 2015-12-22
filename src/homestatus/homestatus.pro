#-------------------------------------------------
#
# Project created by QtCreator 2015-05-10T14:16:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = homestatus
TEMPLATE = app

INCLUDEPATH += /usr/local/qwt-6.1.3-svn/include

LIBS += -L/usr/local/qwt-6.1.3-svn/lib -lqwt -Wl,-rpath,/usr/local/qwt-6.1.3-svn/lib

SOURCES += main.cpp\
        homestatus.cpp

HEADERS  += homestatus.h

FORMS    += homestatus.ui

RESOURCES += \
    hs.qrc

# install
target.path = /usr/bin
INSTALLS += target
