#include "Plateforme.h"
Plateforme::Plateforme() {
    sizeX = 15;
    sizeY = 1;
    pos.x = 0;
    pos.y = 28;
}


bool Plateforme::Move(int keyboardValue)
{
    switch (keyboardValue)
    {
        case LEFT:
            if (pos.x <= 0) return false;
            pos.x--;
            break;
        case RIGHT:
            if (pos.x + sizeX >= RESOLUTION_X) return false;
            pos.x++;
            break;
    }
    return true;
}
