TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
CONFIG      -= flat
HEADERS     += inputs/PhysicalController.h inputs/Controller.h inputs/Keyboard.h components/components.h gameItems/Balle.h gameItems/bricks/Brique.h gameItems/bricks/Briquetest.h gameItems/bricks/BriqueA.h gameItems/bricks/BriqueB.h gameItems/bricks/BriqueC.h gameItems/bricks/BriqueT.h gameItems/bricks/BriqueVoid.h Level.h UI/menu.h gameItems/Plateforme.h gameItems/Myrect.h components/Structs.h GameLogic.h Canevas.h GameLoop.h gameItems/powerups/Powerups.h gameItems/powerups/Extendplatform.h gameItems/powerups/Addballs.h gameItems/powerups/Swapcontrol.h lib/json.hpp lib/SerialPort.hpp
SOURCES     += UI/mainwindow.cpp atariBreakout.cpp inputs/PhysicalController.cpp inputs/Controller.cpp inputs/Keyboard.cpp gameItems/Balle.cpp gameItems/bricks/Brique.cpp gameItems/bricks/Briquetest.cpp gameItems/bricks/BriqueA.cpp gameItems/bricks/BriqueB.cpp gameItems/bricks/BriqueC.cpp gameItems/bricks/BriqueT.cpp gameItems/bricks/BriqueVoid.cpp Level.cpp UI/menu.cpp gameItems/Plateforme.cpp gameItems/Myrect.cpp GameLogic.cpp Canevas.cpp GameLoop.cpp gameItems/powerups/Powerups.cpp gameItems/powerups/Extendplatform.cpp gameItems/powerups/Addballs.cpp gameItems/powerups/Swapcontrol.cpp lib/SerialPort.cpp
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/lib ../atariBreakout/components ../atariBreakout/UI ../atariBreakout/gameItems ../atariBreakout/gameItems/bricks ../atariBreakout/gameItems/powerups
QT          += widgets
		