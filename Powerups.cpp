#include "Powerups.h"

Powerups::Powerups()
{

}

Powerups::~Powerups()
{

}
Powerups::Powerups(Position positionDestroyed,int _height , int _lenght  )
{

	pos = positionDestroyed;
	state = Falling;
	lenght = _lenght;
	height = _height;
	timer = 0;
	
}


void Powerups::update()
{
	if (state == Falling)
	{
		oldpos = pos;
		pos.y += 1;
		
	}
	if (timer >= PTIMELIMIT)
	{
		state = Done;
		
	}
	if (state == Active)
		timer += SLEEP;
}

bool Powerups::checkCollisions(Plateforme _plateforme)
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

				state = Active;
				return true;

			}
		}
	}
	return false;

}


void Powerups::modifyBall(std::vector<Balle*> & ball, Plateforme _plat,bool reset )
{

}
void Powerups::modifyPlateform(Plateforme& platform, bool reset )
{

}
void Powerups::modifyControler(Controller& controller, bool reset )
{

}

void Powerups::setPowerups(std::vector<Balle*>& ball, Plateforme& platform, Controller& controller)
{
	modifyBall(ball,platform);
	modifyPlateform(platform);
	modifyControler(controller);

}
void Powerups::resetPowerups(std::vector<Balle*> &ball, Plateforme& platform, Controller& controller)
{
	modifyBall(ball,platform,true);
	modifyPlateform(platform,true);
	modifyControler(controller,true);

}
void Powerups::draw(char UI[RESMAX_Y][RESMAX_X])
{
	if (state == Falling)
	{
		UI[oldpos.y][oldpos.x] = ' '; //espace a l'ancienne pos de la balle
		UI[pos.y][pos.x] = 'P'; //update la nouvelle pos de la balle dans l'array 
	}
}