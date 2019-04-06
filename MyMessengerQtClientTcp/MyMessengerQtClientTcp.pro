TARGET = MyMessengerQtClientTcp

QT += core
QT -= gui
QT += network

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
