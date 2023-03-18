#include "Addballs.h"


void Addballs::modifyBall(std::vector<Balle*> &ball, bool reset)
{
	if (!reset) {
		if (!ball.empty())
		{
			Position pos = ball[0]->getPos();
			int rayon = ball[0]->getrayon();
			for (int i = 0; i < NUMBER_BALLS; i++)
			{
				pos.x -= i;
				pos.y -= i;
				ball.push_back(new Balle(pos, rayon));

			}
		}
	}
}


Addballs::Addballs(Position positionDestroyed, int height, int lenght) :Powerups(positionDestroyed, height, lenght)
{

}

