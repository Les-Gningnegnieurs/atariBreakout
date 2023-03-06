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
    int rayon;
    Velocity speed;
    int oldPosX;
    int oldPosY;
public:
    Balle(LevelInfos I);

    int getrayon() { return rayon; }
    void update();
    int getoldPosX() { return oldPosX;  };
    int getoldPosY() { return oldPosY;  };
    void draw(char UI[RESMAX_Y][RESMAX_X]);
    bool checkCollision(Position posHit);
    Velocity getSpeed(){return speed;}
    Position getPos() {return pos;}
    void changeVelocity(bool x = 0, bool y = 0);

};

#endif
