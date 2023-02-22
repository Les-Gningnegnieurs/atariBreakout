#include "Briquetest.h"

Briquetest::Briquetest(int x, int y, int l, int h) {
    _posBTest.x = x;
    _posBTest.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _PVini = _PV;
    _etat = Alive;
    //length et height peut-etre a definir
}

Briquetest::~Briquetest() {

}

void Briquetest::update(float timeElapsed) {
}


bool Briquetest::increase_Damage() {
    if (_etat == Destroyed)
        return false;
    _PV--;
    if (_PV == 0)
        _etat = Destroyed;
    else
        _etat = Hurt;
    return true;
}


void Briquetest::draw(std::ostream& s) {
    s << "A:" << _posBTest.x << ", " << _posBTest.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}