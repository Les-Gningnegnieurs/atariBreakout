#include "BriqueVoid.h"

BriqueVoid::BriqueVoid(int x, int y, int l, int h) {
    _posBrique.x = x;
    _posBrique.y = y;
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
void BriqueVoid::draw(std::ostream& s) {
    if (_etat == Destroyed)
        
        for (int i = 0; i < _sizeX; i++) {
            s << " ";
        }

    else
    {
        if (_sizeX == 1)
            s << "*";
        else {
            s << "|";
            for (int i = 1; i < _sizeX - 1; i++) {
                if (_etat == Alive)
                    s << "-";
                else if (_etat == Hurt)
                    s << "X";
            }
            s << "|";
        }
    }
}
void BriqueVoid::afficher(std::ostream& s) {
    s << "V:" << _posBrique.x << ", " << _posBrique.y << ", " << _sizeX << ", " << _sizeY << std::endl;
}
