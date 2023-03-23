

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <chrono>
#include "menu.h"
#include "Canevas.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "inputs/Keyboard.h"
#include "inputs/PhysicalController.h"

using  namespace std::chrono;


class GameLoop {
private:
    Canevas *_canevas;
    Menu _menu;
    gameState _gameState;
    int bg = 0;
    
public:
    Controller* _controller;

    bool over;
    GameLoop();
    void Start();
    void Stop();
    void Pause();
    void update();
    void GameOver();
    void Restart();
    void draw();
    void loadFile();


};


#endif