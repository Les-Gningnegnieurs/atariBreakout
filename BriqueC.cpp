#include "BriqueC.h"
BriqueC::BriqueC(int x, int y, int l, int h) {
    _posBrique.x = x;
    _posBrique.y = y;
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
    s << "C:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}