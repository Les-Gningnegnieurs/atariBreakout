#include "Structs.h"
#include "GameLogic.h"

#ifndef POWERUPS_H
#define POWERUPS_H

class Powerups
{
private:
	Position pos;
	Status state; 
	
public:
	Powerups(Position positionDestroyed);
	~Powerups();
	bool checkCollisions();
	void updatePos();
	virtual void setPowerups();
	virtual void resetPowerups();
	
	
};
#endif
