#include "Structs.h"
#include "GameLogic.h"

#ifndef POWERUPS_H
#define POWERUPS_H

class Powerups
{
private:
	Position pos;
	Status state; 
	int lenght;
	int height;
	int timer;
	
public:
	Powerups(Position positionDestroyed, int height =1 ,int lenght = 1);
	~Powerups();
	void checkCollisions(Plateforme _plateforme);
	void update();
	virtual void setPowerups();
	virtual void resetPowerups();
	void setFalling() { state = Falling; }
	void draw();
	
	
};
#endif
