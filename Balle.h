//
// Created by stao0901 on 2023-02-11.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include"Structs.h"

#ifndef BALLE_H
#define BALLE_H
class Balle{
private:
    Position pos;
    float rayon;
    Velocity speed;
    int maxSpeed;
public:
    Balle(float ray);
    float aire() {return rayon*rayon*M_PI;}
    void update(float timeElapsed);
    void draw();
    Position getPos() {return pos;}
    bool checkCollision();
    void outOfBounds();


};

#endif BALLE_H
