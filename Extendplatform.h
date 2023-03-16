#ifndef EXTENDPLATFORM_H
#define EXTENDPLATFORM_H
#define EXTENDFACTOR 1.5
#include "Powerups.h"

class Extendplatform :public Powerups {
public:
	Extendplatform(Position positionDestroyed, int height = 1, int lenght = 1);
	void modifyPlateform(Plateforme& platform, bool reset);
};

#endif