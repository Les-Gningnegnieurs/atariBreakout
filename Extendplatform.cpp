#include "Extendplatform.h"

void Extendplatform::modifyPlateform(Plateforme& platform, bool reset)
{
	int change = 0;
	if (reset) {
		change = platform.getLenght() / EXTENDFACTOR <= MINSIZE ? MINSIZE : platform.getLenght() / EXTENDFACTOR;
		platform.setLenght(change);
	}
	else 
	{
		change = platform.getLenght() * EXTENDFACTOR >= MAXSIZE ? MAXSIZE : platform.getLenght() * EXTENDFACTOR;
		platform.setLenght(change);
	}
}

Extendplatform::Extendplatform(Position positionDestroyed,  int height , int lenght ) :Powerups( positionDestroyed,    height ,  lenght )
{
	graphic_powerup = new PowerX3("ressources/heart2.png");
	name = "Extendplatform";
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

