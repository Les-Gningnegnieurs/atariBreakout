

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

}

void GameLoop::Stop() {
    _controller->setReverse(false);
    timer->stop();
    _controller->setPower(0);

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
    timer->start();
    _controller->setPower(1);
}

void GameLoop::nextLevel()
{
    _canevas->erase();


    loadFile();
    _window->updateScene(_canevas->getScene());

    timer->start();

}