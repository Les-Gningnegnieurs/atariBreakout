#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include "Structs.h"
#include <QGraphicsPixmapItem>

#include <QDebug>
#include <QFont>
#include <QColor>
#include <QBrush>
#include <QImage>
class MyRect : public QGraphicsRectItem {
public:
	MyRect(LevelInfos I);
	void keyPressEvent(QKeyEvent* event);
private:
	Position posPlat;
	int rows;
	int columns;
	int sizeX;
	int sizeY;
	int Window_X;
	int Window_Y;
};

class Score : public QGraphicsTextItem {
public:
	Score(QGraphicsItem* parent = 0);
	void increase();
	void resetScore();
	int getScore();
	
private:
	int score;
};
class Health : public QGraphicsPixmapItem {
public:
	Health(QGraphicsPixmapItem* parent = 0);
	void decrease();
	int GetHealth();
private:
	int vies;
};

#endif MYRECT_H