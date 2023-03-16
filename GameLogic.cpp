#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic:: GameLogic(LevelInfos i)
{
    _info = i;
    maxSizeX = _info.columns;
    maxSizeY = _info.rows;
    _livesLeft=3;
     _platform=Plateforme(_info);
    _score=0;
    _balls.push_back(new Balle(_info));
    _level = Level(_info);
    for (int i = 0; i < maxSizeY; i++) {
        for (int j = 0; j < maxSizeX; j++) {
            UI[i][j] = ' ';
        }
    }
}

GameLogic::~GameLogic(){
    _balls.clear();
}

void GameLogic:: update(Controller& c)
{
    _level.draw(UI);
    //move plateform
    _platform.move(c.getJoystick().x);
    _platform.update(); //update la position
    _platform.draw(UI); //update le dessin dans le tableau

    for (int i = 0; i < _powers.size(); i++)
    {
        _powers[i]->update(*this);
        if (_powers[i]->getState() == Inactive)
        {
            delete _powers[i];
;             _powers.erase(_powers.begin() + i);
        }
    }

    //update Game / do logic
    for(int i=0; i< _balls.size();i++)
    {
        _balls[i]->update();
        _balls[i]->draw(UI);
    }

    //check les collisions une fois que les positions ont ete updatés
    checkCollisions(); 
    draw(std::cout);
    //Update controller status (LED & bargrpah)
    //TODO quand on vas avoir déterminé une utilité
}

bool GameLogic::isGameOver()
{
    if (_livesLeft<0)  return true;
    else return false;
}

//Retirer les valeurs de limite hardcodé et enovyer balle en reference 
//dans les check collision pour utiliser leur vélocité pour savoir d'ou elles arrivent pour le check colision
//et determiner l'angle de renvoi
void GameLogic::checkCollisions() {
    Position pos;

    for (int i = 0; i < _powers.size(); i++)
    {
        _powers[i]->checkCollisions(_platform,*this);
    }
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        if (pos.y >= maxSizeY) //check si mort
        {
            //_balls[i]->changeVelocity(0, 1); //faire bounce dans le bas
            delete _balls[i];
            _balls.erase(_balls.begin()+i);
        }
        else
        {
            _platform.checkCollision(_balls[i]);
            
            //Balle *b = _balls[i];
            _level.checkCollision(_balls[i], _score);

            if (pos.y <= 0) //Hit  plafond
            {
                _balls[i]->changeVelocity(0, 1);//inverser direction de la balle en Y
            }

            //check walls collision
            if (pos.x <= 0 || pos.x + _balls[i]->getrayon() >= maxSizeX - 1)
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
        }
    }
    if(_balls.empty())
    {
        _livesLeft--;
        Sleep(200);
        Balle* p1 = new Balle(_info);
        _balls.push_back(p1);
    }

}

int GameLogic::getScoreInfo() {
    return _score;
}

void GameLogic::draw(std::ostream& s) {
    //draw bricks
    for (int i = 0; i < maxSizeY; i++) {
        for (int j = 0; j < maxSizeX; j++) {
            s << UI[i][j];
        }
        s << std::endl;
    }
}

std::istream& operator>>(std::istream& s, GameLogic &gl){
    
    s >> gl._level;
    return s;
 }
