#include "BriqueT.h"
BriqueT::BriqueT(int x, int y, int l, int h) {
    setRect(0, 0, l, h);
    setBrush(Qt::darkGray);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _etat = Indestructible;

    //length et height peut-etre a definir
}

BriqueT::~BriqueT() {
    //delete rect;
}




void BriqueT::afficher(std::ostream& s) {
    s << "T:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}