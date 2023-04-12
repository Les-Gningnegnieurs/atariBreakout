TEMPLATE = vcapp
TARGET = testApplication
CONFIG += warn_on qt debug windows console
HEADERS += MenuUtils.h application.h settings.h SelectLevel.h menu.h MainMenu.h   ../atariBreakout/components/Structs.h ../atariBreakout/components/components.h ../atariBreakout/inputs/Controller.h ../atariBreakout/inputs/Keyboard.h ../atariBreakout/inputs/PhysicalController.h ../atariBreakout/lib/json.hpp ../atariBreakout/lib/SerialPort.hpp
SOURCES += MenuUtils.cpp settings.cpp application.cpp SelectLevel.cpp MainMenu.cpp menu.cpp ../atariBreakout/inputs/Controller.cpp ../atariBreakout/inputs/Keyboard.cpp ../atariBreakout/inputs/PhysicalController.cpp ../atariBreakout/lib/SerialPort.cpp
INCLUDEPATH += ../atariBreakout
QT += widgets
