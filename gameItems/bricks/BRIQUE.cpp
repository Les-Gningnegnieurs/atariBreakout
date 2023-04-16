#include "Brique.h"
#define CORNER_FACTOR 10
#define SIDE_FACTOR 15
Brique:: Brique(int x, int y, int l, int h, state s){
    setRect(0, 0, 10, 10);
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
        if (posBa.y == _posBrique.y + rayon && speed.y < 0)
        {
            if (posBa.x == _posBrique.x)
                return DN;
        }
        //collision top
        if (posBa.y == _posBrique.y - rayon && speed.y > 0)
        {
            if (posBa.x == _posBrique.x)
                return UP;
        }
        //collision left
        if (posBa.x == _posBrique.x - rayon && speed.x > 0)
        {
            if (posBa.y == _posBrique.y)
                return LT;
        }
        //collision right
        if (posBa.x == _posBrique.x + rayon && speed.x < 0)
        {
            if (posBa.y == _posBrique.y)
                return RT;
        }
        //collision coin
        //if (posBa.x + speed.x == _posBrique.x
            //&& posBa.y + speed.y == _posBrique.y)
        if ((posBa.x == _posBrique.x - rayon && posBa.y == _posBrique.y - rayon && speed.x > 0 && speed.y > 0) || //coin superieur gauche
            (posBa.x == _posBrique.x - rayon && posBa.y == _posBrique.y + rayon && speed.x > 0 && speed.y < 0) || //coin inferieur gauche
            (posBa.x == _posBrique.x + rayon && posBa.y == _posBrique.y - rayon && speed.x < 0 && speed.y > 0) ||//coin superieur droit
            (posBa.x == _posBrique.x + rayon && posBa.y == _posBrique.y + rayon) && speed.x < 0 && speed.y < 0) //coin inferieur droit (il faut que la balle aille en diagonal gauche)

        {
            return CN;
        }
        return NO;
    }
    else {
        int X_next = posBa.x + speed.x;
        int Y_next = posBa.y + speed.y;

        //if ((posBa.x + rayon * 2 >= _posBrique.x && posBa.x < _posBrique.x + CORNER_FACTOR && posBa.y + rayon * 2 >= _posBrique.y && posBa.y + rayon * 2 < _posBrique.y + CORNER_FACTOR && speed.x > 0 && speed.y > 0) || //coin sup�rieur gauche
        //    (posBa.x + rayon * 2 >= _posBrique.x && posBa.x < _posBrique.x + CORNER_FACTOR && posBa.y <= _posBrique.y + _sizeY -1 && posBa.y > _posBrique.y + _sizeY-1+CORNER_FACTOR && speed.x > 0 && speed.y < 0)||    //coin inf�rieur gauche
        //    (posBa.x <= _posBrique.x + _sizeX -1 && posBa.x > _posBrique.x + _sizeX -1 - CORNER_FACTOR && posBa.y + rayon*2 >= _posBrique.y && posBa.y + rayon*2 < _posBrique.y + CORNER_FACTOR && speed.x < 0 && speed.y > 0)||    //coin sup�rieur droit
        //    (posBa.x <= _posBrique.x + _sizeX - 1 && posBa.x > _posBrique.x + _sizeX - 1 - CORNER_FACTOR && posBa.y <= _posBrique.y + _sizeY-1 && posBa.y > _posBrique.y + _sizeY-1 - CORNER_FACTOR && speed.x<0 && speed.y < 0 ))  //coin inf�rieur droit
        if ((posBa.x + rayon * 2 >= _posBrique.x && posBa.x < _posBrique.x + CORNER_FACTOR && posBa.y + rayon * 2 >= _posBrique.y && posBa.y + rayon * 2 < _posBrique.y + CORNER_FACTOR && speed.x > 0 && speed.y > 0) || //coin sup rieur gauche
        (posBa.x + rayon * 2 >= _posBrique.x && posBa.x < _posBrique.x + CORNER_FACTOR && posBa.y <= _posBrique.y + _sizeY - 1 && posBa.y > _posBrique.y + _sizeY - 1 + CORNER_FACTOR && speed.x > 0 && speed.y < 0) ||    //coin inf rieur gauche
            (posBa.x <= _posBrique.x + _sizeX - 1 && posBa.x > _posBrique.x + _sizeX - 1 - CORNER_FACTOR && posBa.y + rayon * 2 >= _posBrique.y && posBa.y + rayon * 2 < _posBrique.y + CORNER_FACTOR && speed.x < 0 && speed.y > 0) ||    //coin sup rieur droit
            (posBa.x <= _posBrique.x + _sizeX - 1 && posBa.x > _posBrique.x + _sizeX - 1 - CORNER_FACTOR && posBa.y <= _posBrique.y + _sizeY - 1 && posBa.y > _posBrique.y + _sizeY - 1 - CORNER_FACTOR && speed.x < 0 && speed.y < 0))  //coin inf rieur droit
            return CN;
        //collision down
        if (Y_next <= _posBrique.y + (_sizeY - 1) && Y_next > _posBrique.y && speed.y < 0)
        {
            if (posBa.x + rayon*2 > _posBrique.x && posBa.x < _posBrique.x + _sizeX - 1)
            //if (posBa.x + rayon * 2 > _posBrique.x && posBa.x < _posBrique.x + _sizeX - 1)
                return DN;
        }
        //collision top
        if (Y_next + rayon*2 > _posBrique.y && Y_next + rayon*2 < _posBrique.y +_sizeY-1 && speed.y > 0)
        {
            //if (posBa.x + rayon*2 > _posBrique.x && posBa.x < _posBrique.x + _sizeX - 1)
            if (posBa.x + rayon*2  > _posBrique.x && posBa.x < _posBrique.x + _sizeX - 1)
                return UP;
        }
        //collision left
        if (X_next + rayon*2 > _posBrique.x && X_next + rayon*2 <_posBrique.x + SIDE_FACTOR && speed.x > 0)
        {
            //if (posBa.y < _posBrique.y + (_sizeY - 1) && posBa.y + rayon * 2 > _posBrique.y)
            if (Y_next < _posBrique.y + (_sizeY - 1) && Y_next + rayon * 2 > _posBrique.y)
                return LT;
        }
        //collision right
        if (X_next < _posBrique.x + (_sizeX - 1) && X_next > _posBrique.x + _sizeX-1 - SIDE_FACTOR && speed.x < 0)
        {
            //if (posBa.y < _posBrique.y + (_sizeY - 1) && posBa.y + rayon * 2 > _posBrique.y)
            if (Y_next < _posBrique.y + (_sizeY - 1) && Y_next + rayon * 2 > _posBrique.y)
                return RT;
        }
        //if ((X_next + rayon * 2 >= _posBrique.x && X_next < _posBrique.x + CORNER_FACTOR && Y_next + rayon * 2 >= _posBrique.y && Y_next + rayon * 2 < _posBrique.y + CORNER_FACTOR && speed.x > 0 && speed.y > 0) || //coin sup�rieur gauche
        //    (X_next + rayon * 2 >= _posBrique.x && X_next < _posBrique.x + CORNER_FACTOR && Y_next <= _posBrique.y + _sizeY - 1 && Y_next > _posBrique.y + _sizeY - 1 + CORNER_FACTOR && speed.x > 0 && speed.y < 0) ||    //coin inf�rieur gauche
        //    (X_next <= _posBrique.x + _sizeX - 1 && X_next > _posBrique.x + _sizeX - 1 - CORNER_FACTOR && Y_next + rayon * 2 >= _posBrique.y && Y_next + rayon * 2 < _posBrique.y + CORNER_FACTOR && speed.x < 0 && speed.y > 0) ||    //coin sup�rieur droit
        //    (X_next <= _posBrique.x + _sizeX - 1 && X_next > _posBrique.x + _sizeX - 1 - CORNER_FACTOR && Y_next <= _posBrique.y + _sizeY - 1 && Y_next > _posBrique.y + _sizeY - 1 - CORNER_FACTOR && speed.x < 0 && speed.y < 0))  //coin inf�rieur droit
        //    return CN;
        return NO;
    }
    return NO;

}


bool Brique::increase_Damage(std::vector<Powerups*>& p, QGraphicsScene* _scene, Controller& c) {
    if (_etat != Indestructible && _etat != Destroyed)
    {
        _PV--;
        if (_PV <= 0)
        {
            addPowerUp(p, _scene, c);
            this->hide();
        }
        else
            _etat = Hurt;
        return true;
    }
    return false;
}
void Brique::draw(){
    if(!est_Detruite())
        setPos(_posBrique.x, _posBrique.y);
}
/*
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
                UI[_posBrique.y][_posBrique.x] = '�';
            else if (_etat == Hurt)
                UI[_posBrique.y][_posBrique.x] = '#';
        }
        else {
            for (int i = _posBrique.y; i < _posBrique.y + _sizeY; i++) {
                int j = _posBrique.x;
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
*/
void Brique::addPowerUp(std::vector<Powerups*>& p, QGraphicsScene* _scene, Controller& c) {
    std::uniform_real_distribution<double> distribution(0, 99);
    std::default_random_engine generator(rd());
    //int y = distribution(generator);
    _etat = Destroyed;
    int y = 1;
    if (y <= c.getRand() * 5) { //y<=20
        int x = 3;
        //int x = c.getRand();
        switch (x%3){ //x%3
            case 0:
                p.push_back(new Swapcontrol(_scene,_posBrique));
                break;
            case 1:
                p.push_back(new Addballs(_scene,_posBrique));
                break;
            case 2:
                p.push_back(new Extendplatform(_scene,_posBrique));
                break;

        }
        
    }
}
