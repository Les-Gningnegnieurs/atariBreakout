#include "BriqueA.h"

BriqueA::BriqueA(int x, int y, int l, int h) {
    rect = new QGraphicsRectItem();
    rect->setBrush(Qt::blue);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _etat = Alive;
    rect->setRect(x, y, l, h);

    //length et height peut-etre a definir
}

BriqueA::~BriqueA() {
    delete rect;
}



void BriqueA::afficher(std::ostream& s) {
    s << "A:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}