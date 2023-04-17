#include "BriqueA.h"

BriqueA::BriqueA(int x, int y, int l, int h) {
    setRect(0, 0, l, h);
    setBrush(QColor(92, 58, 147));
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _etat = Alive;

    //length et height peut-etre a definir
}

BriqueA::~BriqueA() {
    //delete rect;
}



void BriqueA::afficher(std::ostream& s) {
    s << "A:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}