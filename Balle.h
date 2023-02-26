//
// Created by stao0901 on 2023-02-11.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include"Structs.h"
#include <iostream>
#include <string>
#include <sstream>
#ifndef BALLE_H
#define BALLE_H
class Balle{
private:
    Position pos;
    double rayon;
    Velocity speed;
    int maxSpeed;
public:
    Balle(float ray, int x=0, int y=0);
    double aire() { return rayon * rayon * 3.141593; }
    void update();
    void draw(std::ostream &s);
    bool checkCollision(Position posHit);
    void outOfBounds();
    Velocity getSpeed(){return speed;}
    Position getPos() {return pos;}
    void changeVelocity(bool x = 0, bool y = 0);



};

#endif
