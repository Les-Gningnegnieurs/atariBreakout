

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _keyboard = new Keyboard();
    loadFile();
}
void GameLoop:: Start(){
    _gameState=Running;
}
void GameLoop:: Pause()
{
    _gameState=Paused;
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

void GameLoop:: GameOver(){
    if(_canevas->Is_GameOver())
    {
        Stop();
        _canevas->erase();
        //ouvrir le menu
    }
    else draw();


}

void GameLoop:: update() {
    _keyboard->receiveInputs();
    if (_gameState == Starting)
        Start();
    if (_gameState==Running) {
        _canevas->update(*_keyboard);
    }
    GameOver();
    _keyboard->sendOutputs();

}

void GameLoop:: loadFile(){
    //int value= _menu.Get_Level();
    int value = 2;
    std::stringstream str;
    std::string levelPath;
    str << "level/" << value << ".txt";
    levelPath = str.str();
    std::fstream myfile;
    myfile.open(levelPath,std::ios::in);
    myfile>>*_canevas;
}

void GameLoop::draw()
{
        _canevas->draw(std::cout);
}

