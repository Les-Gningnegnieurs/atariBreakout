#include "Powerups.h"

#ifndef ADDBALLS_H
#define ADDBALLS_H
#define NUMBER_BALLS 2

class Addballs:public Powerups
{
public:
	Addballs(QGraphicsScene* _scene, Position positionDestroyed, int height = 40, int lenght = 40);
	void modifyBall(std::vector<Balle*> & ball, Plateforme _plat, bool reset = false);
	void draw();
	void hide_powerup();
private:
	//PowerX3* graphic_powerup;

};

#endif 