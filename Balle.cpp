#include "Balle.h"
Balle::Balle() //Checker la position
{
    pos.x = 18;
    pos.y = 28;
    speed.y = -1;
    speed.x = -1;
	lives = 5;
}

bool Balle::Update()
{
	pos.x += speed.x;
	pos.y += speed.y;
	
	if (pos.x == 0 || pos.x == RESOLUTION_X - 1) Collision(HORIZONTAL);
	if (pos.y == 0) Collision(VERTICAL);
	if (pos.y == RESOLUTION_Y - 1) return false;
	return true;
}


bool Balle::Collision(int sens)
{
	switch (sens)
	{
		case HORIZONTAL:
			speed.x = -speed.x;
			break;
		
		case VERTICAL:
			speed.y = -speed.y;
			break;
			
		case CORNER:
			speed.x = -speed.x;
			speed.y = -speed.y;
			break;
			
		default:
			return false;
			break;
	}
	return true;
}
