

#include "GameLoop.h"

GameLoop::GameLoop(QObject* parent) : QObject(parent) {   
    _canevas = new Canevas();
    _window = new MainWindow(nullptr, _canevas, _canevas->getScene());
    _controller = new Keyboard();
    _menu.Set_Controller(_controller);

    _gameState = Starting;
    loadFile();
    over = false;

    timer = new QTimer();
    timer->setInterval(SLEEP);
    QObject::connect(timer, &QTimer::timeout, this, &GameLoop::MainGameLoop);
    timer->start();
    //temporaire
    _menu.Set_playing(1);
    //_window->showMenu();
}

void GameLoop::Start() {

    /*while (!_menu.Is_over())
    {
        _menu.print(std::cout);
    }*/

    _controller = _menu.Get_Controller();
    _controller->setPower(true);


    _canevas->erase();
    if (_menu.Is_playing())
        _gameState = Running;
    else
        Stop();

    MainGameLoop();
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
    stopGameLoop();
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
            


           /* std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
            std::cout << std::endl << std::endl << "Paused\t" << "ESC : Resume\t" << "ENTER : QUIT";*/

            //Sleep(200);
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

            //Sleep(150);
            //system("CLS");


        }
    }
    GameOver();

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

void GameLoop::startGameLoop() {
    Start();
}

void GameLoop::stopGameLoop() {
    //� v�rifier
    timer->stop();
    //thread->exit();
}


void GameLoop::MainGameLoop() {
    if (!over) {
        update();
    }
    else {
        Restart();
    }
}