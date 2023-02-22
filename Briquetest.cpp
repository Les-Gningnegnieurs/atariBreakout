#include "Briquetest.h"

Briquetest::Briquetest(int x, int y, int l, int h) {
    _posBTest.x = x;
    _posBTest.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 1;
    _PVini = _PV;
    _etat = Alive;
    //length et height peut-etre a definir
}

Briquetest::~Briquetest() {

}

void Briquetest::update(float timeElapsed) {
}


bool Briquetest::increase_Damage() {
    if (_etat == Destroyed)
        return false;
    _PV--;
    if (_PV == 0)
        _etat = Destroyed;
    else
        _etat = Hurt;
    return true;
}


void Briquetest::draw(std::ostream& s) {
    if (_etat == Destroyed)
        for (int i = 0; i < _sizeX; i++) {
            s << " ";
        }

    else
    {
        if (_sizeX = 1)
            s << "□";
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