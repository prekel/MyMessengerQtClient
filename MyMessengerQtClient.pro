TEMPLATE = subdirs

SUBDIRS += \
    MyMessengerQtClientCore \
    MyMessengerQtClientTcp \
    MyMessengerQtClientGui \
    MyMessengerQtClient \
    MyMessengerQtClientCoreTests

MyMessengerQtClient.depends = MyMessengerQtClientGui MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientGui.depends = MyMessengerQtClientTcp MyMessengerQtClientCore
MyMessengerQtClientTcp.depends = MyMessengerQtClientCore
MyMessengerQtClientCoreTests.depends = MyMessengerQtClientCore
MyMessengerQtClientCore.depends =
