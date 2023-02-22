#include "BriqueT.h"
BriqueT::BriqueT(int x, int y, int l, int h) {
    _posT.x = x;
    _posT.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _PVini = _PV;
    _etat = Indestructible;
    //length et height peut-etre a definir
}

BriqueT::~BriqueT() {

}

void BriqueT::update(float timeElapsed) {
}


void BriqueT::afficher(std::ostream& s) {
    s << "T:" << _posT.x << ", " << _posT.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}