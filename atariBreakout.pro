TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
HEADERS     += inputs/PhysicalController.h inputs/Controller.h inputs/Keyboard.h components/components.h Balle.h Brique.h Briquetest.h BriqueA.h BriqueB.h BriqueC.h BriqueT.h BriqueVoid.h Level.h menu.h Plateforme.h Structs.h GameLogic.h Canevas.h GameLoop.h Powerups.h Extendplatform.h Addballs.h Swapcontrol.h lib/json.hpp lib/SerialPort.hpp
SOURCES     += atariBreakout.cpp inputs/PhysicalController.cpp inputs/Controller.cpp inputs/Keyboard.cpp Balle.cpp Brique.cpp Briquetest.cpp BriqueA.cpp BriqueB.cpp BriqueC.cpp BriqueT.cpp BriqueVoid.cpp Level.cpp menu.cpp Plateforme.cpp GameLogic.cpp Canevas.cpp GameLoop.cpp Powerups.cpp Extendplatform.cpp Addballs.cpp Swapcontrol.cpp lib/SerialPort.cpp
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/lib ../atariBreakout/components
QT          += widgets
		