#include "BriqueB.h"

BriqueB::BriqueB(int x, int y, int l, int h) {
    _posBrique.x = x;
    _posBrique.y = y;
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
    s << "B:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}