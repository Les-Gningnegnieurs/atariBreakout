#include "BriqueC.h"
BriqueC::BriqueC(int x, int y, int l, int h) {
    _posC.x = x;
    _posC.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 3;
    _PVini = _PV;
    _etat = Alive;
    //length et height peut-etre a definir
}

BriqueC::~BriqueC() {

}

void BriqueC::update(float timeElapsed) {
}


void BriqueC::afficher(std::ostream& s) {
    s << "C:" << _posC.x << ", " << _posC.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}