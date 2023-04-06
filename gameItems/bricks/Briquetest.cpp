#include "Briquetest.h"

Briquetest::Briquetest(int x, int y, int l, int h, state s) {
    rect = new QGraphicsRectItem();
    rect->setBrush(Qt::yellow);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _etat = s;
    rect->setRect(x, y, l, h);
    //length et height peut-etre a definir
}

Briquetest::~Briquetest() {
    delete rect;
}



void Briquetest::afficher(std::ostream& s) {
    s << "A:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}