#pragma once
#include "Powerups.h"
class Swapcontrol:public Powerups
{
public:
	void modifyControler(Controller& controller, bool reset = false);
	Swapcontrol(QGraphicsScene* _scene, Position positionDestroyed, int height = 1, int lenght = 1);
	void draw();
	void hide_powerup();
private:
	PowerX3* graphic_powerup;

};

