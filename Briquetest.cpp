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


void Briquetest::afficher(std::ostream& s) {
    s << "A:" << _posBTest.x << ", " << _posBTest.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}