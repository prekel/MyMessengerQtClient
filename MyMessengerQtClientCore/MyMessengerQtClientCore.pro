TARGET = MyMessengerQtClientCore

QT += core
QT -= gui

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    mymessengerqtclientcore.cpp \
    account.cpp \
    Iso8601Time.cpp

HEADERS += \
    mymessengerqtclientcore.h \
    responsecode.h \
    commandname.h \
    account.h \
    Iso8601Time.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
