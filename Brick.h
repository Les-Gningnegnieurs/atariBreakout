#ifndef BRICK_H
#define BRICK_H
#include "Structs.h"
#define ACTIVE 1
#define INACTIVE 0

class Brick
{
private:
    Coordonnees coord;
    bool etat = ACTIVE;
public:
    void Set_Pos(Coordonnees c) {coord.x = c.x; coord.y = c.y;};
    Coordonnees Get_Pos() {return coord;};
    void Collision() {etat = INACTIVE;};
    bool Is_Active() {return etat;};
};

#endif