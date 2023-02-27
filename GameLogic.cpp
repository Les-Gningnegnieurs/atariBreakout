#include "GameLogic.h"

GameLogic::GameLogic()
{
}

GameLogic:: GameLogic(LevelInfos _info)
{
    maxSizeX = _info.columns;
    maxSizeY = _info.rows;
    _livesLeft=3;
     _platform=Plateforme(_info.Plat_length, _info.Plat_heigth,_info.pos_Plat_iniX,_info.pos_Plat_iniY);
    _score=0;
    _balls.push_back(new Balle(_info.ball_radius,_info.pos_Ball_iniX, _info.pos_Ball_iniY));
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
    //move plateform
    _platform.move(c.getJoystick().x);
    _platform.update(); //update la position
    _platform.draw(UI); //update le dessin dans le tableau

    //update Game / do logic
    for(int i=0; i< _balls.size();i++)
    {
        _balls[i]->update();
        _balls[i]->draw(UI);
    }
    _level.draw(UI);

    //check les collisions une fois que les positions ont ete updatés
    checkCollisions(); 

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
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        if (pos.y>25) //le [0,0] est dans le coin Haut-Gauche
        {
            delete _balls[i];
            _balls.erase(_balls.begin()+i);
        }
        else
        {
            if(_platform.checkCollision(pos) || pos.y <= 0) //Hit plateforme ou plafond
            {
                _balls[i]->changeVelocity(0, 1);//inverser direction de la balle en Y
            }

            //check walls collision
            if(pos.x <= 0 || pos.x >= 80) //one of the walls hit
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
            
            //Balle *b = _balls[i];
            _level.checkCollision(_balls[i], _score);
        }
    }
    if(_balls.empty())
    {
        _livesLeft--;
        Balle* p1 = new Balle(5, 5, 5);
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