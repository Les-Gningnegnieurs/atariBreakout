

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include <chrono>
#include "menu.h"
#include "Canevas.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
using  std::chrono;


class GameLoop {
private:
    high_resolution_clock;
    Canevas *_canevas;
    Menu _menu;
    auto lasTickTime;
    gameState _gameState;
public:
    void Start();
    void Stop();
    void Pause();
    void openMenu();
    void update();
    bool GameOver();
    void restart();
    void draw(std::ostream &s);
    void exit();
    void loadFile();


};


#endif