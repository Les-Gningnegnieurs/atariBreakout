#pragma once
#include "Powerups.h"
class Swapcontrol:public Powerups
{
public:
	void modifyControler(Controller& controller, bool reset = false);
	Swapcontrol(Position positionDestroyed, int height = 1, int lenght = 1);
	void draw(char UI[RESMAX_Y][RESMAX_X]);

};

