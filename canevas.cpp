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
void Canevas::draw(ostream &s)
{
	_game.draw(s);
}

void Canevas::update (float ElapsedTime)
{
	_game.update()
}

bool Canevas::Is_GameOver()
{
	return _game.isGameOver();
}
