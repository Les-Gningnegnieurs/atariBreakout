

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _controller = new Keyboard();
    _menu.Set_Controller(_controller);
    _gameState = Starting;
    loadFile();
    over = false;
}

void GameLoop:: Start(){
    
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
        over = true;
    }
    else draw();


}

void GameLoop:: update() {
    if (_gameState == Starting)
        Start();

    _controller->receiveInputs();
    
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
            //Sleep(100);
            //_canevas->update(*_controller);
            //Menu _mmenu;
            //draw();
            //while (_menu.Resume_Menu(std::cout)) _canevas->update(*_controller);
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

