TEMPLATE = subdirs

SUBDIRS += \
    MyMessengerQtClientCore \
    MyMessengerQtClientTcp \
    MyMessengerQtClientGui \
    MyMessengerQtClient

MyMessengerQtClient.depends = MyMessengerQtClientGui MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientGui.depends = MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientTcp.depends = MyMessengerQtClientCore
MyMessengerQtClientCore.depends =
