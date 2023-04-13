#include "canevas.h"


Canevas::Canevas()
{
	_scene = new QGraphicsScene();
	_scene->setSceneRect(0, 0, 1200, 800);
	QPixmap* jeu = new QPixmap("ressources/jeu.png");
	
	_scene->setSceneRect(0, 0, 1200, 800);
	QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(*jeu);

	pixmapItem->setScale(_scene->width() / jeu->width());
	_scene->addItem(pixmapItem);

}

Canevas::~Canevas() {
	delete _scene;
}