#include "Balle.h"
#include "Level.h"
#include "BRIQUE.H"
#include "Plateforme.h"
#include "Controller.h"
#include <vector>
#include "Keyboard.h"
#include <iostream>
#include "Powerups.h"


#ifndef GAMELOGIC_H
#define GAMELOGIC_H
class GameLogic {
private:
    std::vector<Balle*> _balls;
    Level _level;
    LevelInfos _info;
    Plateforme _platform;
    char UI[RESMAX_Y][RESMAX_X];
    int _score;
    int _livesLeft;
    int maxSizeX;
    int maxSizeY;
    std::vector<Powerups> _powers;

    void checkCollisions();
public:
    GameLogic();
    GameLogic(LevelInfos _info);
    ~GameLogic();
    void update(Controller& c);
    void draw(std::ostream &s);
    bool isGameOver();
    int getScoreInfo();

    friend std::istream& operator>>(std::istream& s, GameLogic &gl);
};


#endif
