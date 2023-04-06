#include "canevas.h"


Canevas::Canevas()
{
	_scene = new QGraphicsScene();
	_scene->setSceneRect(0, 0, 1400, 800);
	_view = new QGraphicsView();
	_view->setScene(_scene);
	_view->setFixedSize(1450, 850);

}

Canevas::~Canevas() {
	delete _scene;
	delete _view;
}




std::istream& operator>>(std::istream& s, Canevas& can)
{
	s >> can._info._windowResolutionX;
	s >> can._info._windowResolutionY;
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
	s >> can._info.speed_B_x;
	s >> can._info.speed_B_y;
	//on as set tt ce dont les constructeurs ont besoin et ensuite on px read le reste
	can._scene->setSceneRect(0, 0, can._info._windowResolutionX-50, can._info._windowResolutionY-50);
	can._view->setFixedSize(can._info._windowResolutionX, can._info._windowResolutionY);

	can._game = new GameLogic(can._info, can._scene);
	s >> *can._game;
	can._view->show();
	return s;
}

void Canevas::erase()
{
	system("CLS");
}


// Affiche le tableau à l'écran
void Canevas::draw()
{
	_game->draw();
	//_view->show();
}

void Canevas::update (Controller& c,bool modeaccel)
{
	_game->update(c,modeaccel);
}

bool Canevas::Is_GameOver()
{
	return _game->isGameOver();
}

