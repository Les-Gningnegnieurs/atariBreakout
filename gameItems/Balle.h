//
// Created by stao0901 on 2023-02-11.
//
#ifndef BALLE_H
#define BALLE_H
#define _USE_MATH_DEFINES
#include <cmath>
#include"Structs.h"
#include <iostream>
#include <string>
#include <sstream>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>

class Balle:public QGraphicsEllipseItem{
private:
    Position pos;
    int rayon;
    Velocity speed;
    int oldPosX;
    int oldPosY;
    QGraphicsEllipseItem* circle;
    QGraphicsScene* _scene;
public:
    Balle(QGraphicsScene* scene, Position posB, int radius, int speedX =-1, int speedY=-1);
    Balle(LevelInfos I, QGraphicsScene* scene);
    void setVelocity(int x, int y);
    int getrayon() { return rayon; }
    void update();
    int getoldPosX() { return oldPosX;  };
    int getoldPosY() { return oldPosY;  };
    void draw();
    bool checkCollision(Position posHit);
    Velocity getSpeed(){return speed;}
    Position getPos() {return pos;}
    void changeVelocity(bool x = 0, bool y = 0);
    QGraphicsEllipseItem* getBall() { return circle; }
};

#endif
