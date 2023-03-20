#include "Swapcontrol.h"

Swapcontrol::Swapcontrol(Position positionDestroyed, int height, int lenght) :Powerups(positionDestroyed, height, lenght)
{
	isStackable = false;
	ledInfo.color = 'r';

}


void Swapcontrol::modifyControler(Controller& controller, bool reset )
{
	if (reset)
		controller.setReverse(0);
	else
		controller.setReverse(1);

}

void Swapcontrol:: draw(char UI[RESMAX_Y][RESMAX_X])
{
	if (state == Falling)
	{
		UI[oldpos.y][oldpos.x] = ' '; //espace a l'ancienne pos de la balle
		UI[pos.y][pos.x] = 'D'; //update la nouvelle pos de la balle dans l'array 
	}

}