QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyMessengerQtClient
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientGui/ -lMyMessengerQtClientGui
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientGui/ -lMyMessengerQtClientGuid
else:unix: LIBS += -L$$OUT_PWD/../MyMessengerQtClientGui/ -lMyMessengerQtClientGui

INCLUDEPATH += $$PWD/../MyMessengerQtClientGui
DEPENDPATH += $$PWD/../MyMessengerQtClientGui
