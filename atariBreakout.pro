TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
HEADERS     += inputs/Controller.h inputs/Keyboard.h components/components.h Balle.h Brique.h Briquetest.h BriqueA.h BriqueB.h BriqueC.h BriqueT.h Level.h menu.h Plateforme.h Structs.h
SOURCES     += keyboardTest.cpp inputs/Controller.cpp inputs/Keyboard.cpp Balle.cpp Brique.cpp Briquetest.cpp BriqueA.cpp BriqueB.cpp BriqueC.cpp BriqueT.cpp Level.cpp menu.cpp Plateforme.cpp
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/components
QT          += widgets
		