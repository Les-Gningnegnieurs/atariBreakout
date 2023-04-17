#include "BriqueB.h"

BriqueB::BriqueB(int x, int y, int l, int h) {
    setRect(0,0,l,h);
    setBrush(Qt::cyan);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 2;
    _etat = Alive;

    //length et height peut-etre a definir
}

BriqueB::~BriqueB() {
    //delete rect;
}




void BriqueB::afficher(std::ostream& s) {
    s << "B:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}
void BriqueB::update_hurt(int pv, QGraphicsScene* _scene) {
    if (pv == 1)
    {
        setBrush(Qt::darkCyan);
        fissure = new QGraphicsPixmapItem(QPixmap("ressources/fissure2.png"));
        fissure->setPos(_posBrique.x, _posBrique.y);
        _scene->addItem(fissure);
    }
}
