

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
    Canevas *_canevas;
    Menu _menu;
    gameState _gameState;
public:
    Controller* _keyboard;
    Controller* _manette;

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


};


#endif