TARGET = MyMessengerQtClientCore

QT += core
QT -= gui

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    Parameters/AbstractParameters.h \
    Parameters/CommandType.h \
    Parameters/GetAccountByIdParameters.h \
    Parameters/LoginParameters.h \
    Parameters/Query.h \
    Responses/AbstractResponse.h \
    Responses/GetAccountByIdResponse.h \
    Responses/LoginResponse.h \
    Responses/ResponseCode.h \
    Account.h \
    IJsonSerializable.h \
    Iso8601Time.h \
    JsonConvert.h

SOURCES += \
    Parameters/AbstractParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Responses/AbstractResponse.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/LoginResponse.cpp \
    Account.cpp \
    IJsonSerializable.cpp \
    Iso8601Time.cpp \
    JsonConvert.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
