

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

using  namespace std::chrono;


class GameLoop {
private:
    high_resolution_clock clock;
    Canevas *_canevas;
    Menu _menu;
    steady_clock::time_point lastTickTime;
    gameState _gameState;
    float elapsed;
public:
    Controller* _keyboard;

    GameLoop();
    void Start();
    void Stop();
    void Pause();
    void openMenu();
    void update();
    void GameOver();
    void Restart();
    void draw();
    void Exit();
    void loadFile();
    void GetTimeElapsed();


};


#endif