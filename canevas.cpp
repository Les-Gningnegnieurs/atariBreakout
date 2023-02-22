#include "canevas.h"


Canevas::Canevas(GameLogic in)
{
	_game = in;	
}

Canevas::~Canevas();
{}

istream& Canevas::operator>>(istream& s, Level& l)
{}

void Canevas::erase()
{}


// Affiche le tableau à l'écran
void Canevas::draw()
{
	for (int i = 0; i < RESOLUTION_Y - 1; i++)
	{
		for (int j = 0; j < RESOLUTION_X - 1; j++)
		{
			std::cout << userInterface [i] [j];
		}
		std::cout << endl;
	}
}

void Canevas::update (float ElapsedTime)
{
	_game.update()
}

bool Canevas::Is_GameOver()
{
	return _game.isGameOver();
}
