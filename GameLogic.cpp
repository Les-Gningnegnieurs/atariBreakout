#include "GameLogic.h"

GameLogic:: GameLogic(const int maxX, const int maxY)
{
    maxSizeX = maxX;
    maxSizeY = maxY;
    _livesLeft=3;
    _platform(5,3);
    _score=0;
    balls[0]=new balle(5);
    _controller = Keyboard(); //à changer lorsqu'on vas utiliser une manette
}

GameLogic::~GameLogic(){
    balls.clear();
}

void GameLogic:: update(float timeElapsed)
{
    _controller.receiveInputs(); //get inputs

    //move plateform
    _platform.move(_controller.getJoystick().x);
    _platform.update(timeElapsed);

    //update Game / do logic
    for(int i=0; i<balls.size();i++)
    {
        balls[i]->update(timeElapsed);
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
    for(int i=0; i<balls.size();i++)
    {
        pos=balls[i]->getPos();
        if (pos.y>maxSizeY) //le [0,0] est dans le coin Haut-Gauche
        {
            delete balls[i];
            balls.erase(balls.begin()+i);
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
            

            _level.checkCollision(_balls[i], _score);
        }
    }
    if(balls.empty())
    {
        _livesLeft--;
        balls[0]=new balle(5);
    }

}

int GameLogic::getScoreInfo() {
    return _score;
}

void GameLogic::draw(){
    //draw bricks
    _level.draw();
    
    //draw balls
    for(int i = 0; i < balls.size(); i++){
        balls[i]->draw();
    }

    //draw plateform
    _platform.draw();
}

 friend istream& operator>>(istream& s, GameLogic gl){
    s >> gl._level;
 }