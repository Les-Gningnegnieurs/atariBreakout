#include "canevas.h"


Canevas::Canevas()
{
	//_game=GameLogic(RESOLUTION_X,RESOLUTION_Y);
}




std::istream& operator>>(std::istream& s, Canevas& can)
{
	int x;
	s >> x;    //rows
	_info.rows = x;
	s >> x;    //columns
	_info.columns=x;
	s >> x; //length
	_info.Brick_length = x;
	s >> x;
	_info.Brick_heigth = x;
	s >> x;
	_info.pos_Plat_iniX = x;
	s >> x;
	_info.pos_Plat_iniY = x;
	s >> x;
	_info.Plat_length = x;
	s >> x;
	_info.Plat_heigth= x;
	s >> x;
	_info.pos_Ball_iniX = x;
	s >> x;
	_info.pos_Ball_iniY = x;
	s >> x;
	_info.ball_radius = x;
	//on as set tt ce dont les constructeurs ont besoin et ensuite on px read le reste
	GameLogic _game(_info);
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

void Canevas::update (Controller& c)
{
	_game.update(c);
}

bool Canevas::Is_GameOver()
{
	return _game.isGameOver();
}
