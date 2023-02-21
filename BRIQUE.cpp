#include "Brique.h"

Brique:: Brique(int x, int y, int l, int h){
    _pos.x = x;
    _pos.y = y;
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

bool Brique::checkCollision(Balle&b) {
    Position posB = b.getPos();
    if (_pos.y >=posB.y&& posB.y <= _pos.y + _sizeY)
    {
        if (_pos.x >= posB.x && posB.x <= _pos.x + _sizeX)
        {
            if (top)
                t;
            else if()
        }
    }
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
