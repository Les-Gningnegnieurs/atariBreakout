#include "Powerups.h"

Powerups::Powerups()
{

}

Powerups::~Powerups()
{

}
Powerups::Powerups(QGraphicsScene* scene, Position positionDestroyed,int _height , int _lenght) : _scene(scene)
{
	pos = positionDestroyed;
	state = Falling;
	lenght = _lenght;
	height = _height;
	timer = 0;
	isStackable = true;
	ledInfo.hasTimer = true; 
	ledInfo.color = 'g';
	oldpos.x = pos.x;
	oldpos.y = pos.y;
}


void Powerups::update()
{
	if (state == Falling)
	{
		oldpos = pos;
		pos.y += 2;
		
	}
	if (timer >= PTIMELIMIT)
	{
		state = Done;		
	}
	if (state == Active)
	{
		auto current_time = clock.now();
		auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - last_time);
		last_time = clock.now();
		timer += elapsed_time.count();
	}


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
				last_time = clock.now();
				hide_powerup();
				return true;

			}
		}
	}
	return false;

}


void Powerups::modifyBall(std::vector<Balle*> & ball, Plateforme _plat,bool reset)
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

