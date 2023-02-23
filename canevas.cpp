#include "canevas.h"


Canevas::Canevas()
{
	_game=GameLogic(10,10);
}




std::istream& operator>>(std::istream& s, Canevas& can)
{
	s >> can._game;
    return s;
}

void Canevas::erase()
{
	system("CLS");
}


// Affiche le tableau à l'écran
void Canevas::draw(std::ostream&s)
{
	erase();
	_game.draw(s);
}

void Canevas::update (float ElapsedTime, Controller& c)
{
	_game.update(ElapsedTime, c);
}

bool Canevas::Is_GameOver()
{
	return _game.isGameOver();
}
