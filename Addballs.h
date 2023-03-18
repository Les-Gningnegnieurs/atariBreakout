#include "Powerups.h"

#ifndef ADDBALLS_H
#define ADDBALLS_H
#define NUMBER_BALLS 2

class Addballs:public Powerups
{
public:
	Addballs(Position positionDestroyed, int height = 1, int lenght = 1);
	void modifyBall(std::vector<Balle*> & ball, bool reset = false);


};

#endif 