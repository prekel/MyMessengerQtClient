TEMPLATE = subdirs

SUBDIRS += \
    MyMessengerQtClient \
    MyMessengerQtClientGui \
    MyMessengerQtClientTcp \
    MyMessengerQtClientCore

MyMessengerQtClient.depends = MyMessengerQtClientGui MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientGui.depends = MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientTcp.depends = MyMessengerQtClientCore
MyMessengerQtClientCore.depends =
