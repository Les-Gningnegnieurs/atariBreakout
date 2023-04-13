#include "canevas.h"


Canevas::Canevas()
{
	_scene = new QGraphicsScene();
	_scene->setSceneRect(0, 0, 1200, 800);
	
	//setBackgroundBrush(QBrush(Qt::red));

}

Canevas::~Canevas() {
	delete _scene;
}