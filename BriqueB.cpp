#include "BriqueB.h"

BriqueB::BriqueB(int x, int y, int l, int h) {
    _posB.x = x;
    _posB.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 2;
    _PVini = _PV;
    _etat = Alive;
    //length et height peut-etre a definir
}

BriqueB::~BriqueB() {

}

void BriqueB::update(float timeElapsed) {
}


void BriqueB::afficher(std::ostream& s) {
    s << "B:" << _posB.x << ", " << _posB.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}