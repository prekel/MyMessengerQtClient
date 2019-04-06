TARGET = MyMessengerQtClientCore

QT += core
QT -= gui

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    Iso8601Time.h \
    responsecode.h \
    Parameters/AbstractParameters.h \
    Parameters/CommandType.h \
    Parameters/GetAccountByIdParameters.h \
    Parameters/LoginParameters.h \
    Parameters/Query.h \
    Iso8601Time.h \
    Responses/ResponseCode.h \
    Account.h \
    Responses/GetAccountByIdResponse.h \
    Responses/AbstractResponse.h \
    Responses/LoginResponse.h \
    IJsonSerializable.h

SOURCES += \
    Iso8601Time.cpp \
    Parameters/AbstractParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Iso8601Time.cpp \
    Account.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/AbstractResponse.cpp \
    Responses/LoginResponse.cpp \
    IJsonSerializable.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
