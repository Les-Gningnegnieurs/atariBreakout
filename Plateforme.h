#include "Structs.h"
#include "Balle.h"
#include <iostream>
#include <sstream>
#ifndef PLATEFORME_H
#define PLATEFORME_H


class Plateforme {
private:
    Position pos;
    Velocity speed;
    int rows;
    int columns;
    int sizeX;
    int sizeY;
    int tiltAngle;
    int maxSpeed;
public:
    Plateforme();
    Plateforme(LevelInfos I);
    void checkCollision(Balle *b);
    void update();
    void move(int joystickvalueX);
    void draw(char UI[RESMAX_Y][RESMAX_X]);
    Velocity getSpeed(){return speed;}
    Position getPos(){return pos;}

};

#endif
