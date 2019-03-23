#-------------------------------------------------
#
# Project created by QtCreator 2019-03-22T10:54:39
#
#-------------------------------------------------

QT       -= gui
QT += network

TARGET = MyMessengerQtClientTcp
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        mymessengerqtclienttcp.cpp \
    tcpclient.cpp

HEADERS += \
        mymessengerqtclienttcp.h \
    tcpclient.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -L$$OUT_PWD/../MyMessengerQtClientCore/ -lMyMessengerQtClientCore

INCLUDEPATH += $$PWD/../MyMessengerQtClientCore
DEPENDPATH += $$PWD/../MyMessengerQtClientCore

win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/MyMessengerQtClientCore.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/libMyMessengerQtClientCore.a
