#include "GameLogic.h"

GameLogic:: GameLogic()
{
    _livesLeft=3;
    _platform(5,3);
    _score=0;
    balls[0]=new balle(5);
    fstream Myfile;
    Myfile.open("level.txt",ios::in);
    Myfile>>_level;
    Myfile.close();


}
void GameLogic:: update(float timeElapsed)
{
    _platform.update(timeElapsed);
    for(int i=0; i<balls.size();i++)
    {
        balls[i]->update(timeElapsed);
    }
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
        if (pos.y<0)
        {
            delete balls[i];
            balls.erase(balls.begin()+i);


        }
        else
        {
            _platform.checkCollision(pos);
           if(_level.checkCollision(pos.x,pos.y)) _score++;
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