#include "BriqueC.h"
BriqueC::BriqueC(int x, int y, int l, int h) {
    setRect(0, 0, l, h);
    setBrush(Qt::green);
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 3;
    _etat = Alive;

    //length et height peut-etre a definir
}

BriqueC::~BriqueC() {
    //delete rect;
}




void BriqueC::afficher(std::ostream& s) {
    s << "C:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}

void BriqueC::update_hurt(int pv, QGraphicsScene* _scene) {
    if (pv == 2)
    {
        setBrush(QColor(34, 139, 34));
        fissure = new QGraphicsPixmapItem(QPixmap("ressources/fissure1.png"));
        fissure->setPos(_posBrique.x, _posBrique.y);
        _scene->addItem(fissure);
    }
    else if (pv == 1) {
        delete fissure;
        setBrush(QColor(Qt::darkGreen));
        fissure = new QGraphicsPixmapItem(QPixmap("ressources/fissure2.png"));
        fissure->setPos(_posBrique.x, _posBrique.y);
        _scene->addItem(fissure);
    }
}