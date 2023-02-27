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

class Balle{
private:
    Position pos;
    double rayon;
    Velocity speed;
    int maxSpeed;
    int oldPosX;
    int oldPosY;
public:
    Balle(float radius=1, int posX=8, int posY=8);

    double aire() { return rayon * rayon * 3.141593; }
    void update();
    int getoldPosX() { return oldPosX;  };
    int getoldPosY() { return oldPosY;  };
    void draw(char UI[RESMAX_Y][RESMAX_X]);
    bool checkCollision(Position posHit);
    void outOfBounds();
    Velocity getSpeed(){return speed;}
    Position getPos() {return pos;}
    void changeVelocity(bool x = 0, bool y = 0);



};

#endif
