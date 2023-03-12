
#ifndef POWERUPS_H
#define POWERUPS_H
#include "Structs.h"

#include "Plateforme.h"
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
	void checkCollisions(Plateforme _plateforme, GameLogic& gm);
	void update(GameLogic& gm);
	virtual void setPowerups(GameLogic &gm) = 0;
	virtual void resetPowerups(GameLogic& gm) = 0;
	void setFalling() { state = Falling; }
	void draw();
	Status getState(){ return state; }
	
	
};
#endif
