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

bool Brique::checkCollision(int x, int y) {
    if (_pos.y >= y && y <= _pos.y + _sizeY)
    {
        if (_pos.x >= x && x <= _pos.x + _sizeX)
            return true;
    }
    return false;
}