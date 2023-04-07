

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _controller = new Keyboard();
    _menu.Set_Controller(_controller);
    _gameState = Starting;
    loadFile();
    over = false;
}

void GameLoop::Start() {

    while (!_menu.Is_over())
    {
        _menu.print(std::cout);
    }

    _controller = _menu.Get_Controller();
    _controller->setPower(true);


    _canevas->erase();
    if (_menu.Is_playing())
        _gameState = Running;
    else
        Stop();
}


void GameLoop::Pause()
{
    _gameState = Paused;
}

void GameLoop::Stop() {
    _gameState = Stopped;
}

void GameLoop::Restart()
{
    _canevas->resetScore();
    _gameState = Starting;
    loadFile();
    over = false;
    _menu.Reset();

}

void GameLoop::GameOver() {
    if (_canevas->Is_GameOver())
    {
        Stop();
        _canevas->erase();
        over = true;
    }



}
#include <conio.h>
void GameLoop::update2() {
    _canevas->update2();
}
void GameLoop::update() {
    if (_gameState == Starting)
        Start();

    _controller->receiveInputs();
    
    if (_gameState == Running) {
        _canevas->update(*_controller, _menu.Is_modeAccelerometer());
        if (_controller->getButton(2))
        {
            


            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << "Paused\t" << "ESC : Resume\t" << "ENTER : QUIT";

            Sleep(200);
            _controller->receiveInputs();
           
            while (!_controller->getButton(2) && !_controller->getButton(1))
            {
                
                _controller->receiveInputs();
               

            }
            if (_controller->getButton(1))
            {
                Stop();
                _canevas->erase();
                over = true;
            }

            Sleep(150);
            system("CLS");


        }
    }
    GameOver();

    /*if (bg >= 10)
        bg = 0;
    else
        bg++;
 
    for (int i = 0; i < 10; i++) {
        if (i < bg)
            _controller->setBargraph(i, 1);
        else
            _controller->setBargraph(i, 0);
    }
    Sleep(1000);*/
    _controller->sendOutputs();
}

void GameLoop::loadFile() {
    //int value = _menu.Get_Level();
    int value = 1;
    std::stringstream str;
    std::string levelPath;
    str << "level/" << value << ".txt";
    levelPath = str.str();
    std::fstream myfile;
    myfile.open(levelPath, std::ios::in);
    myfile >> *_canevas;
}

void GameLoop::draw()
{
    _canevas->draw();
}

