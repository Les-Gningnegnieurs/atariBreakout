#include "BriqueC.h"
BriqueC::BriqueC(int x, int y, int l, int h) {
    rect = new QGraphicsRectItem();
    rect->setBrush(Qt::green);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 3;
    _etat = Alive;
    rect->setRect(x, y, l, h);

    //length et height peut-etre a definir
}

BriqueC::~BriqueC() {
    delete rect;
}




void BriqueC::afficher(std::ostream& s) {
    s << "C:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}