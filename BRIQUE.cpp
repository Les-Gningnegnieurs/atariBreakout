#include "Brique.h"

Brique:: Brique(int x = 0, int y = 0, int l, int h){
    _pos.x = x;
    _pos.y = y;
    _sizeX = l;
    _sizeY = h;
    //length et height peut-etre a definir
}

virtual istream& Brique :: importer(istream &s){
    s >> *this;
    return s;
}

