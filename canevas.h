#include "GameLogic.h"
#include <stdlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <Structs.h>



class Canevas
{
private:
	GameLogic* _game;
	int _windowResolutionX = RESOLUTION_X;
	int _windowResolutionY = RESOLUTION_Y;
	LevelInfos _info;
	QGraphicsScene* _scene;
public:
	Canevas();
	~Canevas();
	friend std::istream& operator>>(std::istream& s, Canevas& can);
	void erase();
	void draw();
	void update (Controller& c, bool modeaccel);
	void update2();
	bool Is_GameOver();
	void resetScore() { _game->resetScore(); }
	QGraphicsScene* getScene() { return _scene; }

};
