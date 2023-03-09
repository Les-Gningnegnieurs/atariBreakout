TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
HEADERS     += inputs/Controller.h inputs/Keyboard.h components/components.h Balle.h Brique.h Briquetest.h BriqueA.h BriqueB.h BriqueC.h BriqueT.h BriqueVoid.h Level.h menu.h Plateforme.h Structs.h GameLogic.h Canevas.h GameLoop.h
SOURCES     += atariBreakout.cpp inputs/Controller.cpp inputs/Keyboard.cpp Balle.cpp Brique.cpp Briquetest.cpp BriqueA.cpp BriqueB.cpp BriqueC.cpp BriqueT.cpp BriqueVoid.cpp Level.cpp menu.cpp Plateforme.cpp GameLogic.cpp Canevas.cpp GameLoop.cpp
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/components
QT          += widgets
		