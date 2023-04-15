#include "Extendplatform.h"

void Extendplatform::modifyPlateform(Plateforme& platform, bool reset)
{
	int change = 0;
	if (reset) {
		change = platform.getLenght() / EXTENDFACTOR <= MINSIZE ? MINSIZE : platform.getLenght() / EXTENDFACTOR;
		platform.setLenght(1, change);
	}
	else 
	{
		change = platform.getLenght() * EXTENDFACTOR >= MAXSIZE ? MAXSIZE : platform.getLenght() * EXTENDFACTOR;
		platform.setLenght(1, change);
	}
}

Extendplatform::Extendplatform(QGraphicsScene* _scene, Position positionDestroyed,  int height , int lenght ) :Powerups(_scene, positionDestroyed,    height ,  lenght )
{
	graphic_powerup = new PowerX3("ressources/heart2.png");
	name = "Extendplatform";
	ledInfo.color = 'g';
	graphic_powerup->setPos(positionDestroyed.x, positionDestroyed.y);
	_scene->addItem(graphic_powerup);
	state = Falling;

}
void Extendplatform::draw() {
	if (state == Falling)
	{
		graphic_powerup->setPos(pos.x, pos.y);
	}
}

void Extendplatform::hide_powerup() {
	delete graphic_powerup;
}

