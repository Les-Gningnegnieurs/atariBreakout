#pragma once
#include "Powerups.h"
class Swapcontrol:public Powerups
{
public:
	void modifyControler(Controller& controller, Plateforme& platform, bool reset = false);
	Swapcontrol(QGraphicsScene* _scene, Position positionDestroyed, int height = 40, int lenght = 40);
	void draw();
	void hide_powerup();
private:
	PowerX3* graphic_powerup;

};

