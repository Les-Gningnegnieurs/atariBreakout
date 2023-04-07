#include "BriqueB.h"

BriqueB::BriqueB(int x, int y, int l, int h) {
    setBrush(Qt::cyan);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 2;
    _etat = Alive;
    setRect(x, y, l, h);

    //length et height peut-etre a definir
}

BriqueB::~BriqueB() {
    //delete rect;
}




void BriqueB::afficher(std::ostream& s) {
    s << "B:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}