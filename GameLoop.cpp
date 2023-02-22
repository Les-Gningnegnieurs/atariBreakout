

#include "GameLoop.h"

void GameLoop:: Start(){
    _gameState=Running;
    lastTickTime= high_resolution_clock::now();
}
void GameLoop:: Pause()
{
    _gameState=Paused;
}

void GameLoop::Stop() {
    _gameState=Stopped;
}

void GameLoop:: Restart()
{
    delete _canevas;
    _canevas= new Canevas;
    loadFile();




}
void GameOver(){
    if(_canevas.Is_GameOver())
    {
        Stop();
        _canevas.erase();
        //ouvrir le menu

    }
    else draw();


}

void GameLoop:: update() {

    if (_gameState==Running) {
        _canevas.update(high_resolution_clock::now() - lasTickTime);
        lasTickTime=high_resolution_clock::now();

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

void GameLoop:: draw(std::ostream &s)
{
    _canevas.draw(s);
}