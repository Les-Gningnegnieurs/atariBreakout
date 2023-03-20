

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _controller = new Keyboard();
    _menu.Set_Controller(_controller);
    loadFile();
}

void GameLoop:: Start(){
    _menu.Intro(std::cout);
    while (!_menu.Is_over())
    {
        _menu.print(std::cout);
    }

    _controller = _menu.Get_Controller();

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
    _controller->receiveInputs();
    if (_gameState == Starting)
        Start();
    if (_gameState==Running) {
        _canevas->update(*_controller);
        if (_controller->getButton(2))
        {
            bool start_end = false;
            while (!start_end)
            {
                Sleep(100);
                _controller->receiveInputs();
                start_end = _controller->getButton(2);
            }
            Sleep(100);
        }
    }
    GameOver();
    _controller->sendOutputs();
}

void GameLoop:: loadFile(){
    int value= _menu.Get_Level();
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

