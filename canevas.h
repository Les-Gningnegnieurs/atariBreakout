#include "GameLogic.h"
#include <stdlib.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <Structs.h>
#include <QLabel>
#include <QGraphicsPixmapItem>



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
	bool isCompleted();
	void resetScore() { _game->resetScore(); }
	QGraphicsScene* getScene() { return _scene; }
	int get_score() { return _game->getScoreInfo(); };

};
