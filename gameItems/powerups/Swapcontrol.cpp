#include "Swapcontrol.h"

Swapcontrol::Swapcontrol(QGraphicsScene* _scene, Position positionDestroyed, int height, int lenght) :Powerups(_scene,positionDestroyed, height, lenght)
{
	graphic_powerup = new PowerX3("ressources/powerup_x3.png");
	isStackable = false;
	ledInfo.color = 'r';
	name = "Swapcontrol";
	graphic_powerup->setPos(positionDestroyed.x, positionDestroyed.y);
	_scene->addItem(graphic_powerup);
	state = Falling;

}


void Swapcontrol::modifyControler(Controller& controller, bool reset )
{
	if (reset)
		controller.setReverse(0);
	else
		controller.setReverse(1);

}
void Swapcontrol::draw(){
	if (state == Falling)
	{
		graphic_powerup->setPos(pos.x, pos.y);
	}
}
void Swapcontrol::hide_powerup() {
	delete graphic_powerup;
}
