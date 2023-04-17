

#include "GameLoop.h"

GameLoop::GameLoop(QApplication* app, QObject* parent) : QObject(parent) {   
    _canevas = new Canevas();
    _window = new MainWindow(app, nullptr, _canevas->getScene(),&_menu);
    _controller = new Keyboard();
    //_controller = new PhysicalController("com4");
    _menu.Set_Controller(_controller);

    _gameState = gameState(0);
    over = false;

    timer = new QTimer();
    timer->setInterval(SLEEP);
    QObject::connect(timer, &QTimer::timeout, this, &GameLoop::MainGameLoop);
    QObject::connect(_window, &MainWindow::startGame, this,&GameLoop::Start);
    QObject::connect(this, &GameLoop::gameOver, _window, &MainWindow::showGameOver);
    QObject::connect(_window, &MainWindow::restartGame, this, &GameLoop::Restart);
    QObject::connect(this, &GameLoop::pauseRequested, _window, &MainWindow::showPauseMenu);
    QObject::connect(this, &GameLoop::gameCompleted, _window, &MainWindow::showGameCompleted);
    QObject::connect(_window, &MainWindow::resumeGame, this, &GameLoop::Resume);
    QObject::connect(_window, &MainWindow::nextLevelRequested, this, &GameLoop::nextLevel);
    
}

void GameLoop::Start() {

    
    over = false;
    _controller = _menu.Get_Controller();
    _controller->setPower(true);
    _controller->sendOutputs();
 
    _score = 0;
    _canevas->erase();
   
    
    loadFile();
    _window->updateScene(_canevas->getScene());
    
     timer->start();
    
   

    //_window->showGame();
}


void GameLoop::Pause()
{
    timer->stop();
    _controller->setPower(0);
    _controller->sendOutputs();

}

void GameLoop::Stop() {
    _controller->setReverse(false);
    timer->stop();
    _controller->setPower(0);
    _controller->sendOutputs();

    //_window->showMenu();
}

void GameLoop::Restart()
{
   
    _canevas->resetScore();
    _canevas->erase();
    _controller->setPower(1);
    _controller->sendOutputs();

    loadFile();
    over = false;
    _window->updateScene(_canevas->getScene());
    timer->start();

}

void GameLoop::GameOver() {
    if (_canevas->Is_GameOver())
    {
      
        _controller->receiveInputs();
        _controller->resetAccel();
        _controller->resetButton();
        _controller->resetJoystick();

        _controller->setReverse(false);
        _controller->setPower(0);
        _controller->sendOutputs();
   
        Stop();
        over = true;
        for (int i = 0; i < 10; i++)
        {
            _controller->setBargraph(i, 0);
        }
        emit gameOver(_canevas->get_score() + _score);
        _score = 0;
    }
}

void GameLoop::update() {
  
    _controller->receiveInputs();
    
     
    _canevas->update(*_controller, _menu.Is_modeAccelerometer());
        
        
           
           
                
               
               

            
     if (_controller->getButton(2))
     {
          Pause();
          emit pauseRequested(_canevas->get_score());
          

     }
        
    
    GameOver();
    IsgameCompleted();

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

void GameLoop::IsgameCompleted()
{
    if (_canevas->isCompleted())
    {
        Stop();
        for(int i=0;i<10;i++)
        {
            _controller->setBargraph(i, 0);
        }
        _score += _canevas->get_score();
        emit gameCompleted(_score);
    }
}

void GameLoop::Resume()
{
    _controller->setPower(1);
    _controller->receiveInputs();
    _controller->resetButton();
    _controller->sendOutputs();

    timer->start();

    

}

void GameLoop::nextLevel()
{
   
    _controller->setPower(1);
    _controller->receiveInputs();
    _controller->resetAccel();
    _controller->resetButton();
    _controller->resetJoystick();
    _controller->sendOutputs();

    _canevas->erase();


    loadFile();
    _window->updateScene(_canevas->getScene());

    timer->start();

}