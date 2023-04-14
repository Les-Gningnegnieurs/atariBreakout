#ifndef EXTENDPLATFORM_H
#define EXTENDPLATFORM_H
#define EXTENDFACTOR 1.5
#define MAXSIZE 473
#define MINSIZE 140
#include "Powerups.h"

class Extendplatform :public Powerups {
public:
	Extendplatform(QGraphicsScene* _scene,Position positionDestroyed, int height = 40, int lenght = 40);
	void modifyPlateform(Plateforme& platform, bool reset);
	void draw();
	void hide_powerup();
private:
	//PowerX3* graphic_powerup;
};

#endif