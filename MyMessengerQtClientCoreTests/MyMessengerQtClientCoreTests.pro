TARGET = MyMessengerQtClientCoreTests

include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

QT += core
QT -= gui

HEADERS += \
        tst_testcase1.h

SOURCES += \
        main.cpp

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
