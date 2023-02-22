#include "Brique.h"

Brique:: Brique(int x, int y, int l, int h){
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _PVini = _PV;
    _etat = Destroyed;
    //length et height peut-etre a definir
}
Brique::~Brique() {

}
bool Brique::est_Detruite() {
    if (_etat == Destroyed)
        return true;
    return false;
}
state Brique::getstate() {
    return _etat;
}

void Brique::setstate(state& s) {
    _etat = s;
}

bool Brique::checkCollision(Balle *b) {
    Position posB = b->getPos();
    if (_posBrique.y >=posB.y&& posB.y <= _posBrique.y + _sizeY)
    {
        if (_posBrique.x >= posB.x && posB.x <= _posBrique.x + _sizeX)
        {
            if (checkTop(posB))
            {
                b->changeVelocity(0,1);
                return true;
            }
            else if(checkBot(posB))
            {
                b->changeVelocity(0,1);
                return true;
            }
            else if (checkRight(posB))
            {
                b->changeVelocity(1,0);
                return true;
            }
            else if(checkLeft(posB))
            {
                b->changeVelocity(1,0);
                return true;
            }

        }
    }
    return false;
}

bool Brique:: checkTop(Position posB)
{
    if (posB.y<=(1/20*(_posBrique.y+_sizeY))) return true;
    return false;


}

bool Brique:: checkBot(Position posB)
{
    if (posB.y>=(19/20*(_posBrique.y+_sizeY))) return true;
    return false;


}

bool Brique:: checkRight(Position posB)
{
    if (posB.x>=(19/20*(_posBrique.x+_sizeX))) return true;
    return false;


}

bool Brique:: checkLeft(Position posB)
{
    if (posB.x<=(1/20*(_posBrique.x+_sizeX))) return true;
    return false;

}


bool Brique::increase_Damage() {
    if (_etat == Destroyed)
        return false;
    _PV--;
    if (_PV == 0)
        _etat = Destroyed;
    else
        _etat = Hurt;
    return true;
}
