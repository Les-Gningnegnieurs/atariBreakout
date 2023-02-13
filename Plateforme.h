#include "Structs.h"
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
    Plateforme(int length,int height);
    bool checkCollision();
    void update(float timeElapsed);
    void move(int joystickvalueX);
    void draw();



};

#endif PLATEFORME_H
