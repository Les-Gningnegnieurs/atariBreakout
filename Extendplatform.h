#ifndef EXTENDPLATFORM_H
#define EXTENDPLATFORM_H
#define EXTENDFACTOR 1.5
#include "Powerups.h"

class Extendplatform :public Powerups {

	void setPowerups(GameLogic& gm);
	void resetPowerups(GameLogic& gm);

};

#endif