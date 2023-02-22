#include "Balle.h"
#include "Level.h"
#include "BRIQUE.H"
#include "Plateforme.h"
#include "Controller.h"
#include <vector>
#include "Keyboard.h"
#include <iostream>



#ifndef GAMELOGIC_H
#define GAMELOGIC_H
class GameLogic {
private:
    std::vector<Balle*> _balls;
    Level _level;
    Plateforme _platform;
    Controller _controller;
    int _score;
    int _livesLeft;
    int maxSizeX;
    int maxSizeY;

    void checkCollisions();
public:
    GameLogic();
    GameLogic(int maxX, int maxY);
    ~GameLogic();
    void update(float timeElapsed);
    void draw(std::ostream& s);
    bool isGameOver();
    int getScoreInfo();

    friend std::istream& operator>>(std::istream& s, GameLogic &gl);
};


#endif
