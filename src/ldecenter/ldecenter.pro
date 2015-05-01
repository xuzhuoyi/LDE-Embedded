TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    form.cpp \
    customerqlabel.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

FORMS += \
    form.ui

HEADERS += \
    form.h \
    customerqlabel.h
    
DESTDIR += ../../usr/bin
