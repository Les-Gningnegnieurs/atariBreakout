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
			
			
				
				
				ball.push_back(new Balle(_scene, posP, rayon,-3,-3));
				ball.push_back(new Balle(_scene,posP, rayon, 3, -3 ));
				ball.push_back(new Balle(_scene, posP, rayon, 0, -3));

		
		}
	}
}


Addballs::Addballs(Position positionDestroyed, int height, int lenght) :Powerups(_scene, positionDestroyed, height, lenght)
{
	ledInfo.hasTimer = false;
	name = "Addballs";

}

