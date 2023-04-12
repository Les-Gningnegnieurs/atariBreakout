#ifndef TESTBALLE_H
#define TESTBALLE_H
#include <QObject>
#include <QGraphicsEllipseItem>
#include "Structs.h"
#include "Level.h"
#include "Plateforme.h"
#include "Myrect.h"
class testBalle : public QObject, public QGraphicsEllipseItem {
	Q_OBJECT
public:
	testBalle(Position posB, int radius, int speedX, int speedY);
	bool checkCollisions();
public slots:
	void move();
private:
	Position _Position;
	int rayon;
	Velocity speed;
	int oldPosX;
	int oldPosY;

};
#endif
