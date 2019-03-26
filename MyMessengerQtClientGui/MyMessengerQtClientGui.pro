TARGET = MyMessengerQtClientGui

QT += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientCore/release/ -lMyMessengerQtClientCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientCore/debug/ -lMyMessengerQtClientCore
else:unix: LIBS += -L$$OUT_PWD/../MyMessengerQtClientCore/ -lMyMessengerQtClientCore

INCLUDEPATH += $$PWD/../MyMessengerQtClientCore
DEPENDPATH += $$PWD/../MyMessengerQtClientCore

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/release/libMyMessengerQtClientCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/debug/libMyMessengerQtClientCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/release/MyMessengerQtClientCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/debug/MyMessengerQtClientCore.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientCore/libMyMessengerQtClientCore.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientTcp/release/ -lMyMessengerQtClientTcp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MyMessengerQtClientTcp/debug/ -lMyMessengerQtClientTcp
else:unix: LIBS += -L$$OUT_PWD/../MyMessengerQtClientTcp/ -lMyMessengerQtClientTcp

INCLUDEPATH += $$PWD/../MyMessengerQtClientTcp
DEPENDPATH += $$PWD/../MyMessengerQtClientTcp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/release/libMyMessengerQtClientTcp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/debug/libMyMessengerQtClientTcp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/release/MyMessengerQtClientTcp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/debug/MyMessengerQtClientTcp.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../MyMessengerQtClientTcp/libMyMessengerQtClientTcp.a
