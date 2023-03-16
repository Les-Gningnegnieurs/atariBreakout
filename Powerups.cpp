#include "Powerups.h"

Powerups::Powerups()
{

}
Powerups::Powerups(Position positionDestroyed, LevelInfos i,int _height , int _lenght  )
{
	maxSizeY = i.rows;
	pos = positionDestroyed;
	state = Inactive;
	lenght = _lenght;
	height = _height;
	timer = 0;
	
}

void Powerups::update(GameLogic& gm)
{
	if (state == Falling)
	{
		pos.y -= 1;
		
	}
	if (timer >= PTIMELIMIT)
	{
		state = Inactive;
		resetPowerups(gm);
	}
	if (state == Active)
		timer += SLEEP;
}

void Powerups::checkCollisions(Plateforme _plateforme, GameLogic& gm)
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
				setPowerups(gm);
				state = Active;

			}
		}

		if (pos.y - height >= maxSizeY)
		{
			state = Inactive;
		}
	}


}
