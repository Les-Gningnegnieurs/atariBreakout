#include "Structs.h"
#include <iostream>
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
    Plateforme(int length,int height, int x, int y);
    bool checkCollision(Position posHit);
    void update(float timeElapsed);
    void move(int joystickvalueX);
    void draw();
    Velocity getSpeed(){return speed;}
    Position getPos(){return pos;}

};

#endif
