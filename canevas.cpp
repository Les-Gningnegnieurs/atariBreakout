#include "canevas.h"


Canevas::Canevas()
{
	_game=GameLogic(7,17);
}




std::istream& operator>>(std::istream& s, Canevas& can)
{
	s >> can._game;
    return s;
}

void Canevas::erase(std::ostream &s)
{

}


// Affiche le tableau à l'écran
void Canevas::draw(std::ostream &s)
{
	_game.draw(s);
}

void Canevas::update (float ElapsedTime)
{
	_game.update(ElapsedTime);
}

bool Canevas::Is_GameOver()
{
	return _game.isGameOver();
}
