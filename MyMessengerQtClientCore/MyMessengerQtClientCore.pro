TARGET = MyMessengerQtClientCore

QT += core
QT -= gui

TEMPLATE = lib

CONFIG += staticlib
CONFIG += c++14

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    Entities/Account.h \
    Entities/Dialog.h \
    Entities/Message.h \
    Parameters/AbstractParameters.h \
    Parameters/CommandType.h \
    Parameters/CreateDialogParameters.h \
    Parameters/GetAccountByIdParameters.h \
    Parameters/GetDialogByIdParameters.h \
    Parameters/GetMessageLongPoolParameters.h \
    Parameters/GetMessagesParameters.h \
    Parameters/LoginParameters.h \
    Parameters/Query.h \
    Parameters/RegisterParameters.h \
    Parameters/SendMessageParameters.h \
    Responses/AbstractResponse.h \
    Responses/CreateDialogResponse.h \
    Responses/GetAccountByIdResponse.h \
    Responses/GetDialogByIdResponse.h \
    Responses/GetMessageLongPoolResponse.h \
    Responses/GetMessagesResponse.h \
    Responses/LoginResponse.h \
    Responses/RegisterResponse.h \
    Responses/ResponseCode.h \
    Responses/SendMessageResponse.h \
    IJsonSerializable.h \
    Iso8601Time.h \
    JsonConvert.h


SOURCES += \
    Entities/Account.cpp \
    Entities/Dialog.cpp \
    Entities/Message.cpp \
    Parameters/AbstractParameters.cpp \
    Parameters/CreateDialogParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/GetDialogByIdParameters.cpp \
    Parameters/GetMessageLongPoolParameters.cpp \
    Parameters/GetMessagesParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Parameters/RegisterParameters.cpp \
    Parameters/SendMessageParameters.cpp \
    Responses/AbstractResponse.cpp \
    Responses/CreateDialogResponse.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/GetDialogByIdResponse.cpp \
    Responses/GetMessageLongPoolResponse.cpp \
    Responses/GetMessagesResponse.cpp \
    Responses/LoginResponse.cpp \
    Responses/RegisterResponse.cpp \
    Responses/SendMessageResponse.cpp \
    IJsonSerializable.cpp \
    Iso8601Time.cpp \
    JsonConvert.cpp


unix {
    target.path = /usr/lib
    INSTALLS += target
}
