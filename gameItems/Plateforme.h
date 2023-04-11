#ifndef PLATEFORME_H
#define PLATEFORME_H

#include "Structs.h"
#include "Balle.h"
#include <iostream>
#include <sstream>
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>
#include <QGraphicsScene>

class Plateforme {
private:
    Position pos;
    Velocity speed;
    int rows;
    int columns;
    int sizeX;
    int sizeY;
    QGraphicsRectItem* rect;
    QGraphicsScene* _scene;
    int Window_X;
    int Window_Y;
public:
    Plateforme();
    Plateforme(LevelInfos I, QGraphicsScene* scene);
    void checkCollision(Balle *b);
    void update();
    void move(int joystickvalueX);
    void draw();
    Velocity getSpeed(){return speed;}
    Position getPos(){return pos;}
    int getLenght() { return sizeX; }
    int getHeight() { return sizeY; }
    void setLenght(int l) { sizeX = l; }
    QGraphicsRectItem* getplat() { return rect; }
    void update2();
    void move2();

};

#endif
