

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _keyboard = new Keyboard();
    //_manette = new Manette();
    loadFile();
}
void GameLoop:: Start(){
    _menu.Intro(std::cout);
    while (!_menu.Is_over())
    {
        _menu.print(std::cout);
    }
    _canevas->erase();
    if (_menu.Is_playing())
        _gameState = Running;
    else
        Stop();
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
    //_manette->receiveInputs();
    if (_gameState == Starting)
        Start();
    if (_gameState==Running) {
        //remplacer par _canevas->update(_menu.getModeManette() ? *_manette : *_keyboard);
        _canevas->update(*_keyboard);
    }
    GameOver();
    _keyboard->sendOutputs();
    //_manette->sendOutputs();

}

void GameLoop:: loadFile(){
    int value= _menu.Get_Level();
    //int value = 3;
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

