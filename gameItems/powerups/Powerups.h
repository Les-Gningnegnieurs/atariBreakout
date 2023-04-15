
#ifndef POWERUPS_H
#define POWERUPS_H
#include "Structs.h"
#include "Balle.h"
#include "Plateforme.h"
#include "Controller.h"
#include <chrono>
#include <vector>
#include <QGraphicsScene>
#include "Myrect.h"
class GameLogic;


class Powerups
{
protected:
	Position pos;
	Position oldpos;
	Status state; 
	int lenght;
	int height;
	double timer;
	int maxSizeY;
	std::chrono::steady_clock clock;
	std::chrono::time_point<std::chrono::steady_clock> last_time;
	virtual void modifyBall(std::vector<Balle*>& ball, Plateforme _plat, bool reset = false, int rand = 1);
	virtual void modifyPlateform(Plateforme& platform, bool reset = false);
	virtual void modifyControler(Controller& controller, Plateforme& platform, bool reset = false);
	bool isStackable;
	PowerupsLED ledInfo;
	std::string name = "Powerups";
	QGraphicsScene* _scene;
	PowerX3* graphic_powerup;
	
	
public:
	Powerups();
	Powerups(QGraphicsScene* scene, Position positionDestroyed,  int height = 40 ,int lenght = 40);
	~Powerups();
	bool checkCollisions(Plateforme _plateforme);
	void update();
	void setPowerups(std::vector<Balle*> &ball, Plateforme& platform, Controller& controller);
	void resetPowerups(std::vector<Balle*> & ball, Plateforme& platform, Controller& controller);
	void setFalling() { state = Falling; }
	virtual void draw()=0;
	Status getState() { return state; };
	void setState(Status s) { state = s; };
	Position getPos() { return pos; };
	int getHeight() { return height; };
	void resetTimer() { timer = 0; }
	bool getStackable(){ return isStackable; }
	PowerupsLED getLedinfo() { return ledInfo;}
	double getTimer() { return timer; }
	std::string getName() { return name; }
	virtual void hide_powerup() = 0;
	

	
};
#endif
