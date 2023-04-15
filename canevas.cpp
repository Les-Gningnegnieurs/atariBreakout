#include "canevas.h"


Canevas::Canevas()
{
	_scene = new QGraphicsScene();
	_scene->setSceneRect(0, 0, 1200, 800);
	_game = nullptr;
	
	
	
}

Canevas::~Canevas() {
	_scene->clear();
	delete _scene;
}
void Canevas::update2() {
	//_game->update2();
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
	s >> can._info.maxspeed_B;
	
	//on as set tt ce dont les constructeurs ont besoin et ensuite on px read le reste
	can._scene->setSceneRect(0, 0, can._info._windowResolutionX, can._info._windowResolutionY);
	if (can._game != nullptr)
		delete can._game;
	

	can._game = new GameLogic(can._info, can._scene);
	s >> *can._game;
	//can.show();
	return s;
}

void Canevas::erase()
{
	delete _scene;
	_scene = new QGraphicsScene;
	_scene->setSceneRect(0, 0, 1200, 800);
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

bool Canevas::isCompleted()
{
	return _game->isCompleted();
}