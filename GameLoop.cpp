

#include "GameLoop.h"

GameLoop::GameLoop(QApplication* app, QObject* parent) : QObject(parent) {   
    _canevas = new Canevas();
    _window = new MainWindow(app, nullptr, _canevas->getScene());
    _controller = new Keyboard();
    _menu.Set_Controller(_controller);

    _gameState = gameState(0);
    loadFile();
    over = false;

    timer = new QTimer();
    timer->setInterval(SLEEP);
    QObject::connect(timer, &QTimer::timeout, this, &GameLoop::MainGameLoop);
    //temporaire
    _menu.Set_playing(1);
    Start();
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

    //_window->showGame();
    timer->start();
}


void GameLoop::Pause()
{
    _gameState = Paused;
}

void GameLoop::Stop() {
    _gameState = Stopped;
    timer->stop();
    //_window->showMenu();
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

void GameLoop::update() {
    if (_gameState == Starting)
        Start();

    _controller->receiveInputs();
    
    if (_gameState == Running) {
        _canevas->update(*_controller, _menu.Is_modeAccelerometer());
        if (_controller->getButton(2))
        {
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
    //À vérifier
    timer->stop();
}


void GameLoop::MainGameLoop() {
    if (!over) {
        update();
    }
    else {
        Restart();
    }
}