#include "BriqueVoid.h"

BriqueVoid::BriqueVoid(int x, int y, int l, int h) {
    _posBVoid.x = x;
    _posBVoid.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _PVini = _PV;
    _etat = Destroyed;
}
BriqueVoid::~BriqueVoid() {

}
void BriqueVoid::update(float timeElapsed) {

}
void BriqueVoid::afficher(std::ostream& s) {
    s << "V:" << _posBVoid.x << ", " << _posBVoid.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}
