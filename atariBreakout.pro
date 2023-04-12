TEMPLATE = vcapp
TARGET = atariBreakout
CONFIG += warn_on qt debug windows console
HEADERS += UI/MenuUtils.h application.h UI/settings.h UI/SelectLevel.h UI/menu.h UI/MainMenu.h   ../atariBreakout/components/Structs.h ../atariBreakout/components/components.h ../atariBreakout/inputs/Controller.h ../atariBreakout/inputs/Keyboard.h ../atariBreakout/inputs/PhysicalController.h ../atariBreakout/lib/json.hpp ../atariBreakout/lib/SerialPort.hpp
SOURCES += UI/MenuUtils.cpp UI/settings.cpp application.cpp UI/SelectLevel.cpp UI/MainMenu.cpp UI/menu.cpp ../atariBreakout/inputs/Controller.cpp ../atariBreakout/inputs/Keyboard.cpp ../atariBreakout/inputs/PhysicalController.cpp ../atariBreakout/lib/SerialPort.cpp
INCLUDEPATH += ../atariBreakout
QT += widgets
