#include "BriqueA.h"
BriqueA::BriqueA(int x, int y, int l, int h) {
    _posA.x = x;
    _posA.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _PVini = _PV;
    _etat = Indestructible;
    //length et height peut-etre a definir
}

BriqueA::~BriqueA() {

}

void BriqueA::update(float timeElapsed) {
}


void BriqueA::afficher(std::ostream& s) {
    s << "A:" << _posA.x << ", " << _posA.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}