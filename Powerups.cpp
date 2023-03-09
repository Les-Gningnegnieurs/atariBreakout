#include "Powerups.h"
Powerups::Powerups(Position positionDestroyed, int _height = 1, int _lenght = 1)
{
	pos = positionDestroyed;
	state = Inactive;
	lenght = _lenght;
	height = _height;
	
}

void Powerups::update()
{
	if (state == Falling)
	{
		pos.y -= 1;
		timer += 50;
	}
	if (timer >= PTIMELIMIT)
	{
		state = Inactive;
	}
}

void Powerups::checkCollisions(Plateforme _plateforme)
{
	Position posPlat = _plateforme.getPos();
	int platHeight = _plateforme.getHeight();
	int platLenght = _plateforme.getLenght();
	
	if (state == Falling)
	{
		if (pos.y >= posPlat.y - platHeight)
		{
			if (pos.x + lenght >= posPlat.x && pos.x <= posPlat.x + platLenght)
			{
				setPowerups();

			}
		}


	}


}
