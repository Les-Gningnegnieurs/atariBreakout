#ifndef BALLE_H
#define BALLE_H
#include"Structs.h"
#include <iostream>
#define HORIZONTAL 1
#define VERTICAL 2
#define CORNER 3


class Balle{
private:
    Coordonnees pos;
    Coordonnees speed;
    int lives;
public:
    Balle();
    bool Update();
    bool Collision(int sens);
    Coordonnees getSpeed(){return speed;}
    Coordonnees getPos() {return pos;}

};

#endif
