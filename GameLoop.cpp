

#include "GameLoop.h"

GameLoop::GameLoop(QApplication* app, QObject* parent) : QObject(parent) {   
    _canevas = new Canevas();
    _window = new MainWindow(app, nullptr, _canevas->getScene(),&_menu);
    _controller = new Keyboard();
    //_controller = new PhysicalController("com4");
    _menu.Set_Controller(_controller);

    _gameState = gameState(0);
    loadFile();
    over = false;

    timer = new QTimer();
    timer->setInterval(SLEEP);
    QObject::connect(timer, &QTimer::timeout, this, &GameLoop::MainGameLoop);
    QObject::connect(_window, &MainWindow::startGame, this,&GameLoop::Start);
    QObject::connect(this, &GameLoop::gameOver, _window, &MainWindow::showGameOver);
    QObject::connect(_window, &MainWindow::restartGame, this, &GameLoop::Restart);
    QObject::connect(this, &GameLoop::pauseRequested, _window, &MainWindow::showMenu);
    
}

void GameLoop::Start() {

    
    over = false;
    _controller = _menu.Get_Controller();
    _controller->setPower(true);
 
    
    _canevas->erase();
   
    
    loadFile();
    _window->updateScene(_canevas->getScene());
    
     _gameState = Running;
     timer->start();
    
   

    //_window->showGame();
}


void GameLoop::Pause()
{
}

void GameLoop::Stop() {
    timer->stop();
    //_window->showMenu();
}

void GameLoop::Restart()
{
   
    _canevas->resetScore();
    _canevas->erase();

    loadFile();
    over = false;
    _window->updateScene(_canevas->getScene());
    timer->start();

}

void GameLoop::GameOver() {
    if (_canevas->Is_GameOver())
    {
        _controller->setReverse(false);
        Stop();
        over = true;
        emit gameOver(_canevas->get_score());
    }
}

void GameLoop::update() {
  
    _controller->receiveInputs();
    
     
    _canevas->update(*_controller, _menu.Is_modeAccelerometer());
        
        
           
           
                
               
               

            
     if (_controller->getButton(2))
     {
          Stop();
          emit pauseRequested();
          

          over = true;
     }
        
    
    GameOver();

    _controller->sendOutputs();
}

void GameLoop::loadFile() {
    int value = _menu.Get_Level();
  
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
}


void GameLoop::MainGameLoop() {
    if (!over) {
        update();
    }
    else {
        Restart();
    }
}