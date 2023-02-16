#include "Briquetest.h"

Briquetest::Briquetest(int x = 0, int y = 0, int l=4, int h=1) {
    _pos.x = x;
    _pos.y = y;
    _sizeX = l;
    _sizeY = h;
    //length et height peut-etre a definir
}

Briquetest::~Briquetest() {

}

bool Briquetest::checkCollision(int x, int y) {
    return true;
}

void Briquetest::update(float timeElapsed) {
    
}

bool Briquetest::est_Detruite() {
    return true;
}


state Briquetest::getstate() {
    return _etat;
}

bool Briquetest::setPV(state state) {
    return true;
}

bool Briquetest::increase_Damage() {
    return true;
}

std::istream& Briquetest::importer(istream& s) {
    return s;
}

void Briquetest::afficher(ostream& s) {
    
}