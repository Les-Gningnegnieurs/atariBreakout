#include "GameLogic.h"

GameLogic::GameLogic()
{
    
}
GameLogic:: GameLogic(const int maxX, const int maxY)
{
    maxSizeX = maxX;
    maxSizeY = maxY;
    _livesLeft=3;
     _platform=Plateforme(5, 3,(maxX/2)-(5/2),maxY);
    _score=0;
    _balls.push_back(new Balle(5,(maxX/2)-(5/2),maxY-3));
}

GameLogic::~GameLogic(){
    _balls.clear();
}

void GameLogic:: update(Controller& c)
{
    //move plateform
    _platform.move(c.getJoystick().x);
    _platform.update();

    //update Game / do logic
    for(int i=0; i< _balls.size();i++)
    {
        _balls[i]->update();
    }
    _level.update();

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

void GameLogic::draw(std::ostream&s){
    //draw bricks
    for(int i=0; i<_level.getRows();i++)
    {
        _level.levelDrawline(s,i);
         s<<std::endl;
    }
    
    //draw balls
    for(int i = 0; i < _balls.size(); i++){
        _balls[i]->draw(s);
    }

    //draw plateform
    _platform.draw(s);
}

std::istream& operator>>(std::istream& s, GameLogic &gl){
    s >> gl._level;
    return s;
 }