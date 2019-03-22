QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyMessengerQtClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp

unix|win32: LIBS += -L$$OUT_PWD/../MyMessengerQtClientGui/ -lMyMessengerQtClientGui
INCLUDEPATH += $$PWD/../MyMessengerQtClientGui
DEPENDPATH += $$PWD/../MyMessengerQtClientGui

unix|win32: LIBS += -L$$OUT_PWD/../MyMessengerQtClientCore/ -lMyMessengerQtClientCore
INCLUDEPATH += $$PWD/../MyMessengerQtClientCore
DEPENDPATH += $$PWD/../MyMessengerQtClientCore
win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/MyMessengerQtClientCore.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/libMyMessengerQtClientCore.a


unix|win32: LIBS += -L$$OUT_PWD/../MyMessengerQtClientTcp/ -lMyMessengerQtClientTcp
INCLUDEPATH += $$PWD/../MyMessengerQtClientTcp
DEPENDPATH += $$PWD/../MyMessengerQtClientTcp
win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/MyMessengerQtClientTcp.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/libMyMessengerQtClientTcp.a
