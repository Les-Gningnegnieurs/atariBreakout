TEMPLATE = vcapp
TARGET = testApplication
CONFIG += warn_on qt debug windows console
HEADERS += MenuUtils.h application.h settings.h SelectLevel.h menu.h MainMenu.h   ../Appli/components/Structs.h ../Appli/components/components.h ../Appli/inputs/Controller.h ../Appli/inputs/Keyboard.h ../Appli/inputs/PhysicalController.h ../Appli/lib/json.hpp ../Appli/lib/SerialPort.hpp
SOURCES += MenuUtils.cpp settings.cpp application.cpp SelectLevel.cpp MainMenu.cpp menu.cpp ../Appli/inputs/Controller.cpp ../Appli/inputs/Keyboard.cpp ../Appli/inputs/PhysicalController.cpp ../Appli/lib/SerialPort.cpp
INCLUDEPATH += ../Appli
QT += widgets
