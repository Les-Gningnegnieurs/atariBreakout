#include "BriqueVoid.h"

BriqueVoid::BriqueVoid(int x, int y, int l, int h) {
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _etat = Destroyed;
}
BriqueVoid::~BriqueVoid() {

}


void BriqueVoid::afficher(std::ostream& s) {
    s << "V:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}
