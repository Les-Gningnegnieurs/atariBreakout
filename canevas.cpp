#include "canevas.h"


Canevas::Canevas(GameLogic in)
{
	_game = in;	
}

Canevas::~Canevas();
{}


std::istream& operator>>(std::istream& s, Level& l)
{
	s >> _game._level;
    return s;
}

void Canevas::erase(std::ostream &s)
{

}


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
