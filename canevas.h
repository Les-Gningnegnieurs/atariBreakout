#include "GameLogic.h"
#include <stdlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#define RESOLUTION_X 80
#define RESOLUTION_Y 25


class Canevas
{
private:
	GameLogic* _game;
	int _windowResolutionX = RESOLUTION_X;
	int _windowResolutionY = RESOLUTION_Y;
	LevelInfos _info;
	QGraphicsScene* _scene;
	QGraphicsView* _view;
public:
	Canevas();
	~Canevas();
	friend std::istream& operator>>(std::istream& s, Canevas& can);
	void erase();
	void draw();
	void update (Controller& c, bool modeaccel);
	bool Is_GameOver();
	void resetScore() { _game->resetScore(); }
	
	

};
