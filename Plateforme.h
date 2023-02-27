#include "Structs.h"
#include <iostream>
#include <sstream>
#ifndef PLATEFORME_H
#define PLATEFORME_H


class Plateforme {
private:
    Position pos;
    Velocity speed;
    int sizeX;
    int sizeY;
    int tiltAngle;
    int maxSpeed;
public:
    Plateforme();
    Plateforme(int length,int height, int x=0, int y=0);
    bool checkCollision(Position posHit);
    void update();
    void move(int joystickvalueX);
    void draw(char UI[RESMAX_Y][RESMAX_X]);
    Velocity getSpeed(){return speed;}
    Position getPos(){return pos;}

};

#endif
