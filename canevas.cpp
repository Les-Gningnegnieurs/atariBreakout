#include "canevas.h"


Canevas::Canevas()
{
	//_game=GameLogic(RESOLUTION_X,RESOLUTION_Y);
}




std::istream& operator>>(std::istream& s, Canevas& can)
{
	 
	s >> can._info.rows;
	s >> can._info.columns;
	s >> can._info.Brick_length;
	s >> can._info.Brick_heigth;
	s >> can._info.pos_Plat_iniX;
	s >> can._info.pos_Plat_iniY;
	s >> can._info.Plat_length;
	s >> can._info.Plat_heigth;
	s >> can._info.pos_Ball_iniX;
	s >> can._info.pos_Ball_iniY;
	s >> can._info.ball_radius;
	//on as set tt ce dont les constructeurs ont besoin et ensuite on px read le reste
	can._game= GameLogic(can._info);
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
