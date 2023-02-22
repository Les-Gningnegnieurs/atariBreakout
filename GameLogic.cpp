#include "GameLogic.h"

GameLogic:: GameLogic(const int maxX, const int maxY)
{
    maxSizeX = maxX;
    maxSizeY = maxY;
    _livesLeft=3;
    Plateforme _platform(5, 3,(maxX/2)-(5/2),MAXY);
    _score=0;
    _balls[0]=new Balle(5,(maxX/2)-(5/2),MAXY-3);
    _controller = Keyboard(); //à changer lorsqu'on vas utiliser une manette
}

GameLogic::~GameLogic(){
    _balls.clear();
}

void GameLogic:: update(float timeElapsed)
{
    _controller.receiveInputs(); //get inputs

    //move plateform
    _platform.move(_controller.getJoystick().x);
    _platform.update(timeElapsed);

    //update Game / do logic
    for(int i=0; i< _balls.size();i++)
    {
        _balls[i]->update(timeElapsed);
    }
    _level.update(timeElapsed);

    //check les collisions une fois que les positions ont ete updatés
    checkCollisions(); 

    //Update controller status (LED & bargrpah)
    //TODO quand on vas avoir déterminé une utilité

    //send outputs
    _controller.sendOutputs();
}

bool GameLogic::isGameOver()
{
    if (_livesLeft<0)  return true;
    else return false;
}

void GameLogic::checkCollisions() {
    Position pos;
    for(int i=0; i< _balls.size();i++)
    {
        pos= _balls[i]->getPos();
        if (pos.y>maxSizeY) //le [0,0] est dans le coin Haut-Gauche
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
            if(pos.x <= 0 || pos.x >= maxSizeX) //one of the walls hit
                _balls[i]->changeVelocity(1, 0); //inverse le vecteur X pour éloigner du mur
            
            //Balle *b = _balls[i];
            _level.checkCollision(_balls[i], _score);
        }
    }
    if(_balls.empty())
    {
        _livesLeft--;
        _balls[0]=new Balle(5);
    }

}

int GameLogic::getScoreInfo() {
    return _score;
}

void GameLogic::draw(std::ostream &s){
    //draw bricks
    for(int i=0; i<_level.getRows();i++)
    {
        _level.levelDrawline(s,i);
        s<<endl;
    }
    
    //draw balls
    for(int i = 0; i < _balls.size(); i++){
        _balls[i]->draw(s);
    }

    //draw plateform
    _platform.draw(s);
}

std::istream& operator>>(std::istream& s, GameLogic gl){
    s >> gl._level;
    return s;
 }