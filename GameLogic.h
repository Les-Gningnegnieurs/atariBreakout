#include "Balle.h"
#include "Level.h"
#include "BRIQUE.H"
#include "Plateforme.h"
#include "Controller.h"
#include <vector>


#ifndef GAMELOGIC_H
#define GAMELOGIC_H
class GameLogic {
private:
    std::vector<Balle*> balls;
    Level _level;
    Plateforme _platform;
    Controller _controller;
    int _score;
    int _livesLeft;

public:
    void update(float timeElapsed
    void draw();
    void checkCollisions();
    bool isGameOver();
    int getScoreInfo();


};

#endif
