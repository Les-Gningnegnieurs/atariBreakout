
#ifndef POWERUPS_H
#define POWERUPS_H
#include "Structs.h"
#include "GameLogic.h"

class Powerups
{
private:
	Position pos;
	Status state; 
	int lenght;
	int height;
	int timer;
	int maxSizeY;
	
public:
	Powerups();
	Powerups(Position positionDestroyed, LevelInfos i, int height =1 ,int lenght = 1);
	~Powerups();
	void checkCollisions(Plateforme _plateforme);
	void update();
	virtual void setPowerups() = 0;
	virtual void resetPowerups() = 0;
	void setFalling() { state = Falling; }
	void draw();
	Status getState(){ return state; }
	
	
};
#endif
