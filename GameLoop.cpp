

#include "GameLoop.h"

void GameLoop:: Start(){
    _gameState=Running;
}
void GameLoop:: Pause()
{
    _gameState=Paused;
}
float GameLoop::GetTimeElapsed()
{
     auto tick = clock.now();
     auto int_ms = duration_cast<std::chrono::milliseconds>(tick - lastTickTime);
     float elapsed = int_ms.count();
     return elapsed;
}
void GameLoop::Stop() {
    _gameState=Stopped;
}

void GameLoop::Restart()
{
    delete _canevas;
    _canevas= new Canevas;
    loadFile();




}
bool GameLoop::GameOver(){
    if (_canevas->Is_GameOver())
    {
        Stop();
        _canevas->erase(std::cout);
        //ouvrir le menu

    }
    else draw(std::cout);


}

void GameLoop:: update() {

    if (_gameState==Running) {
        float elapsed = GetTimeElapsed();
        _canevas->update(elapsed);
    }
    GameOver();

}

void GameLoop:: loadFile(){
    int value= _menu.Get_Level();
    std::string levelPath= "level/"+value+".txt";
    fstream myfile;
    myfile.open(levelPath,ios::in);
    myfile>>_canevas;
}

void GameLoop::draw(std::ostream& s)
{
    _canevas->draw(s);
}