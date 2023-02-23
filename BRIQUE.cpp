#include "Brique.h"

Brique:: Brique(int x, int y, int l, int h, state s){
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
    _PVini = _PV;
    _etat = s;
    //length et height peut-etre a definir
}
Brique::~Brique() {

}
bool Brique::est_Detruite() {
    if (_etat == Destroyed)
        return true;
    return false;
}
state Brique::getstate() {
    return _etat;
}
/// <summary>
/// Alive(1):PV=PVMAX,   Hurt(1): PV entre PVMAX et 0,    Destroyed(0): PV=0
/// </summary>
/// <param name="s"></param>
void Brique::setstate(state s) {
    _etat = s;
}

bool Brique::checkCollision(Balle *b) {
    Position posB = b->getPos();
    if (_posBrique.y +_sizeY >=posB.y&& posB.y >= _posBrique.y )
    {
        if (_posBrique.x +_sizeX>= posB.x && posB.x >= _posBrique.x )
        {
           if (checkBot(posB))
            {
                b->changeVelocity(0, 1);
                return true;
            }
           else if (checkTop(posB))
            {
                b->changeVelocity(0,1);
                return true;
            }
            
             if (checkRight(posB))
            {
                b->changeVelocity(1,0);
                return true;
            }
            else if(checkLeft(posB))
            {
                b->changeVelocity(1,0);
                return true;
            }

        }
    }
    return false;
}

bool Brique:: checkTop(Position posB)
{
    if (posB.y<=(1/20*(_posBrique.y+_sizeY))) return true;
    return false;


}

bool Brique:: checkBot(Position posB)
{
    if (posB.y>=(19/20*(_posBrique.y+_sizeY))) return true;
    return false;


}

bool Brique:: checkRight(Position posB)
{
    if (posB.x>=(19/20*(_posBrique.x+_sizeX))) return true;
    return false;


}

bool Brique:: checkLeft(Position posB)
{
    if (posB.x<=(1/20*(_posBrique.x+_sizeX))) return true;
    return false;

}


bool Brique::increase_Damage() {
    if (_etat == Destroyed)
        return false;
    else if (_etat != Indestructible)
    {
        _PV--;
        if (_PV <= 0)
            _etat = Destroyed;
        else
            _etat = Hurt;
        return true;
    }
}

void Brique::draw(std::ostream& s) {
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