TARGET = MyMessengerQtClientCore

QT += core
QT -= gui

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    *.cpp

HEADERS += \
    *.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
