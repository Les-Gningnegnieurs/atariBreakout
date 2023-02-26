#include "Structs.h"


#ifndef PLATEFORME_H
#define PLATEFORME_H
#define LEFT 1
#define RIGHT 2

class Plateforme {
private:
    Coordonnees pos;
    int sizeX;
    int sizeY;
public:
    Plateforme();
    bool Move(int keyboardValue);
    Coordonnees GetPos(){return pos;}
    
    int Get_X() {return pos.x;};
    int Get_Y() {return pos.y;};
    int Get_SizeX() {return sizeX;};

};

#endif
