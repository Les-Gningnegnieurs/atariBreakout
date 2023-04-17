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
#include <QString>
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
class Plati : public QGraphicsPixmapItem {
public:
	Plati(int plat_length, int plat_heigth, QString filepath = "ressources/bar1.png");
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

class PowerX3 : public QGraphicsPixmapItem {
public:
	PowerX3(QString filepath = "ressources/powerup_x3.png");
};

class Control_mode : public QGraphicsPixmapItem {
public:
	Control_mode(int height, int length, QString filepath = "ressources/controller.png");
};

#endif MYRECT_H