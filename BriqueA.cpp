#include "BriqueA.h"

BriqueA::BriqueA(int x, int y, int l, int h) {
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _PVini = _PV;
    _etat = Alive;
    //length et height peut-etre a definir
}

BriqueA::~BriqueA() {

}

void BriqueA::update(float timeElapsed) {
}


void BriqueA::afficher(std::ostream& s) {
    s << "A:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}