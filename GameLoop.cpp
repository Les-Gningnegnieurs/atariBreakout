

#include "GameLoop.h"

GameLoop::GameLoop() {
    _canevas = new Canevas();
    _keyboard = new Keyboard();
    loadFile();
}
void GameLoop:: Start(){
    _gameState=Running;
    elapsed = 0;
}
void GameLoop:: Pause()
{
    _gameState=Paused;
}
void GameLoop::GetTimeElapsed()
{
     auto tick = clock.now();
     auto int_ms = duration_cast<std::chrono::milliseconds>(tick - lastTickTime);
     lastTickTime = tick;
     elapsed = int_ms.count();
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
    GetTimeElapsed();
    if (_gameState == Starting)
        Start();
    if (_gameState==Running) {
        _canevas->update(elapsed, *_keyboard);
    }
    GameOver();
    _keyboard->sendOutputs();

}

void GameLoop:: loadFile(){
    //int value= _menu.Get_Level();
    int value = 1;
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
    if (drawElapsed >= 200) {
        drawElapsed = 0;
        std::stringstream s;
        _canevas->draw(s);
        std::cout << s.str();
    }
    else
        drawElapsed += elapsed;
}