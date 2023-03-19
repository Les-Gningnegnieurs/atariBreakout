#include "Brique.h"
Brique:: Brique(int x, int y, int l, int h, state s){
    _posBrique.x = x;
    _posBrique.y = y;
    _sizeX = l;
    _sizeY = h;
    _PV = 0;
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

Collision Brique::checkCollision(Balle* b) {
    Position posBa = b->getPos();
    int rayon = b->getrayon();
    Velocity speed = b->getSpeed();
    //collision down
    if (_sizeX == 1) {
        if (posBa.y == _posBrique.y + rayon)
        {
            if (posBa.x == _posBrique.x)
                return DN;
        }
        //collision top
        if (posBa.y == _posBrique.y - rayon)
        {
            if (posBa.x == _posBrique.x)
                return UP;
        }
        //collision left
        if (posBa.x == _posBrique.x - rayon)
        {
            if (posBa.y == _posBrique.y)
                return LT;
        }
        //collision right
        if (posBa.x == _posBrique.x + _sizeX + rayon)
        {
            if (posBa.y == _posBrique.y)
                return RT;
        }
        //collision coin
        if (posBa.x + speed.x == _posBrique.x
            && posBa.y + speed.y == _posBrique.y)
        {
            return CN;
        }
        return NO;
    }
    else
        //collision down
        if (posBa.y == _posBrique.y + rayon && speed.y < 0)  
        {
            if (posBa.x >= _posBrique.x && posBa.x <=_posBrique.x+_sizeX-1 )
                return DN;
        }
    //collision top
    if (posBa.y == _posBrique.y - rayon && speed.y > 0) 
    {
        if (posBa.x >= _posBrique.x && posBa.x <= _posBrique.x + _sizeX-1)
            return UP;
    }
    //collision left
    if (posBa.x == _posBrique.x - rayon && speed.x > 0)
    {
        if (posBa.y == _posBrique.y)
            return LT;
    }
    //collision right
    if (posBa.x == _posBrique.x + (_sizeX-1) +rayon && speed.x < 0)
    {
        if (posBa.y == _posBrique.y)
            return RT;
    }
    //collision coin
    if ((posBa.x == _posBrique.x-rayon && posBa.y == _posBrique.y-rayon && speed.x > 0 && speed.y > 0 )|| //coin superieur gauche
        (posBa.x == _posBrique.x-rayon && posBa.y == _posBrique.y+rayon && speed.x > 0 && speed.y < 0)|| //coin inferieur gauche
        (posBa.x == _posBrique.x+(_sizeX-1)+rayon && posBa.y == _posBrique.y-rayon && speed.x < 0 && speed.y > 0)||//coin superieur droit
        (posBa.x == _posBrique.x+(_sizeX-1)+rayon && posBa.y == _posBrique.y+rayon) && speed.x < 0 && speed.y < 0) //coin inferieur droit (il faut que la balle aille en diagonal gauche)

    {
        return CN;
    }
    return NO;
    /*if (posBa.y + rayon >= _posBrique.y && posBa.y - rayon <= _posBrique.y)
    {
        if (_posBrique.x + _sizeX >= posBa.x - rayon && posBa.x + rayon >= _posBrique.x)
        {
            //checkbot
            if (speed.y <= 0) {
                if (speed.x >= 0 && posBa.y == _posBrique.y) return LT;//côté gauche 
                    //c'est un calcul d'intervalles, pas un test d'égalité**
                else if (speed.x <= 0 && posBa.y == _posBrique.y) return RT; //côté droit
                else return DN; //sinon = hit du bottom

            }
            else if (speed.y >= 0) {//checktop
                if (speed.x >= 0 && posBa.y == _posBrique.y) return LT;//côté gauche 
                    //c'est un calcul d'intervalles, pas un test d'égalité**
                else if (speed.x <= 0 && posBa.y == _posBrique.y)return RT; //côté droit
                else return UP ; //sinon = hit du top
            }
        }
    }
    return NO;*/
    
}


bool Brique::increase_Damage(std::vector<Powerups*>& p,int &score) {
    if (_etat != Indestructible && _etat != Destroyed)
    {
        _PV--;
        if (_PV <= 0)
        {
            addPowerUp(p);
            score++;
        }
        else
            _etat = Hurt;
        return true;
    }
    return false;
}

void Brique::draw(char UI[RESMAX_Y][RESMAX_X]) {
    if (est_Detruite()) {
        if (_sizeX == 1 && _sizeY == 1)
        {
            UI[_posBrique.y][_posBrique.x] = ' ';
        }
        else {
            for (int i = _posBrique.y; i < _posBrique.y + _sizeY; i++) {
                for (int j = _posBrique.x; j < _posBrique.x + _sizeX; j++) {
                    UI[i][j] = ' ';
                }
            }
        }
    }

    else
    {
        if (_sizeX == 1)
        {
            if (_etat == Alive)
                UI[_posBrique.y][_posBrique.x] = 'X';
            else if (_etat == Indestructible)
                UI[_posBrique.y][_posBrique.x] = '¼';
            else if (_etat == Hurt)
                UI[_posBrique.y][_posBrique.x] = '#';
        }
        else {
            int j = _posBrique.x;
            for (int i = _posBrique.y; i < _posBrique.y + _sizeY; i++) {
                UI[i][j] = '[';
                j++;
                for (j; j < _posBrique.x + _sizeX-1; j++) {
                    if (_etat == Alive)
                        UI[i][j] = 'X';
                    else if (_etat == Hurt)
                        UI[i][j] = 'x';
                    else if (_etat == Indestructible) {
                        UI[i][j] = '%';
                    }
                }
                UI[i][j] = ']';
            }
        }
    }
}

void Brique::addPowerUp(std::vector<Powerups*>& p) {
    int y = rand() ;
    _etat = Destroyed;
    if (y % 100 <= 20)
        p.push_back(new Addballs(_posBrique));
}
