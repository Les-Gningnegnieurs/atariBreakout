TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
HEADERS     += inputs/Controller.h inputs/Keyboard.h components/components.h
SOURCES     += keyboardTest.cpp inputs/Controller.cpp inputs/Keyboard.cpp
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/components
QT          += widgets
