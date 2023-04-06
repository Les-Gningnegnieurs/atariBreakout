#include "BriqueVoid.h"

BriqueVoid::BriqueVoid(int x, int y, int l, int h) {
    //rect = new QGraphicsRectItem();
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _etat = Destroyed;
}
BriqueVoid::~BriqueVoid() {
    //delete rect;
}


void BriqueVoid::afficher(std::ostream& s) {
    s << "V:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}
