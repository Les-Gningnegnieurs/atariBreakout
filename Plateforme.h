#ifndef PLATEFORME_H
#define PLATEFORME_H

#include "Structs.h"
#include "Balle.h"
#include <iostream>
#include <sstream>

class Plateforme {
private:
    Position pos;
    Velocity speed;
    int rows;
    int columns;
    int sizeX;
    int sizeY;
public:
    Plateforme();
    Plateforme(LevelInfos I);
    void checkCollision(Balle *b);
    void update();
    void move(int joystickvalueX);
    void draw(char UI[RESMAX_Y][RESMAX_X]);
    Velocity getSpeed(){return speed;}
    Position getPos(){return pos;}
    int getLenght() { return sizeX; }
    int getHeight() { return sizeY; }
    int setLenght(int l) { sizeX = l; }

};

#endif
