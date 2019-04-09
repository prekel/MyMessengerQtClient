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
    IJsonSerializable.h \
    Iso8601Time.h \
    JsonConvert.h \
    Entities/Dialog.h \
    Parameters/AbstractParameters.h \
    Parameters/CommandType.h \
    Parameters/GetAccountByIdParameters.h \
    Parameters/LoginParameters.h \
    Parameters/Query.h \
    Responses/AbstractResponse.h \
    Responses/GetAccountByIdResponse.h \
    Responses/LoginResponse.h \
    Responses/ResponseCode.h \
    Entities/Account.h \
    IJsonSerializable.h \
    Iso8601Time.h \
    JsonConvert.h \
    Entities/Message.h \
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
    Parameters/AbstractParameters.h \
    Parameters/CommandType.h \
    Parameters/CreateDialogParameters.h \
    Parameters/DialogSessionParameters.h \
    Parameters/GetAccountByIdParameters.h \
    Parameters/GetDialogByIdParameters.h \
    Parameters/GetMessageLongPoolParameters.h \
    Parameters/GetMessagesParameters.h \
    Parameters/LoginParameters.h \
    Parameters/Query.h \
    Parameters/RegisterParameters.h \
    Parameters/SendMessageParameters.h

SOURCES += \
    Parameters/AbstractParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Responses/AbstractResponse.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/LoginResponse.cpp \
    IJsonSerializable.cpp \
    Iso8601Time.cpp \
    JsonConvert.cpp \
    Entities/Dialog.cpp \
    Parameters/AbstractParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Responses/AbstractResponse.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/LoginResponse.cpp \
    Entities/Account.cpp \
    IJsonSerializable.cpp \
    Iso8601Time.cpp \
    JsonConvert.cpp \
    Entities/Message.cpp \
    Responses/AbstractResponse.cpp \
    Responses/CreateDialogResponse.cpp \
    Responses/GetAccountByIdResponse.cpp \
    Responses/GetDialogByIdResponse.cpp \
    Responses/GetMessageLongPoolResponse.cpp \
    Responses/GetMessagesResponse.cpp \
    Responses/LoginResponse.cpp \
    Responses/RegisterResponse.cpp \
    Responses/SendMessageResponse.cpp \
    Parameters/AbstractParameters.cpp \
    Parameters/CreateDialogParameters.cpp \
    Parameters/DialogSessionParameters.cpp \
    Parameters/GetAccountByIdParameters.cpp \
    Parameters/GetDialogByIdParameters.cpp \
    Parameters/GetMessageLongPoolParameters.cpp \
    Parameters/GetMessagesParameters.cpp \
    Parameters/LoginParameters.cpp \
    Parameters/Query.cpp \
    Parameters/RegisterParameters.cpp \
    Parameters/SendMessageParameters.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}
