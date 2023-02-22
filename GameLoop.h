

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <chrono>
#include "menu.h"
#include "Canevas.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
using  namespace std::chrono;


class GameLoop {
private:
    high_resolution_clock clock;
    Canevas *_canevas;
    Menu _menu;
    steady_clock::time_point lastTickTime;
    gameState _gameState;
public:
    void Start();
    void Stop();
    void Pause();
    void openMenu();
    void update();
    bool GameOver();
    void Restart();
    void draw(std::ostream &s);
    void Exit();
    void loadFile();
    float GetTimeElapsed();


};


#endif