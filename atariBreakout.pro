TEMPLATE     = vcapp
TARGET       = atariBreakout
CONFIG      += warn_on qt debug windows console
CONFIG      -= flat
HEADERS     += UI/CustomButton.h UI/MenuUtils.h UI/Settings.h UI/MainMenu.h UI/mainWindow.h UI/SelectLevel.h  components/components.h components/Structs.h  Canevas.h GameLoop.h
SOURCES     += UI/CustomButton.cpp UI/MenuUtils.cpp UI/Settings.cpp UI/MainMenu.cpp UI/mainWindow.cpp UI/SelectLevel.cpp atariBreakout.cpp   Canevas.cpp GameLoop.cpp 
INCLUDEPATH += ../atariBreakout ../atariBreakout/inputs ../atariBreakout/lib ../atariBreakout/lib ../atariBreakout/components ../atariBreakout/UI ../atariBreakout/gameItems ../atariBreakout/gameItems/bricks ../atariBreakout/gameItems/powerups
QT          += widgets
QT          += core
		