#include "Addballs.h"


void Addballs::modifyBall(std::vector<Balle*> &ball, Plateforme _plat, bool reset)
{
	if (!reset) {
		if(!ball.empty())
		
		{
			int rayon = ball[0]->getrayon();
			Position posP = _plat.getPos();
			int sizeX = _plat.getLenght() / 2;
			posP.y--;
			posP.x += sizeX;
			
			
				
				
				ball.push_back(new Balle(posP, rayon,-1,-1));
				ball.push_back(new Balle(posP, rayon, 1, -1));
				ball.push_back(new Balle(posP, rayon, 0, -1));

		
		}
	}
}


Addballs::Addballs(Position positionDestroyed, int height, int lenght) :Powerups(positionDestroyed, height, lenght)
{
	graphic_powerup = new PowerX3("ressources/powerup_x3.png");
	ledInfo.hasTimer = false;
	name = "Addballs";
	graphic_powerup->setPos(positionDestroyed.x, positionDestroyed.y);
	_scene->addItem(graphic_powerup);
	state = Falling;
}

void Addballs::draw() {
	if (state == Falling)
	{
		graphic_powerup->setPos(pos.x, pos.y);
	}
}
void Addballs::hide_powerup() {
	delete graphic_powerup;
}
