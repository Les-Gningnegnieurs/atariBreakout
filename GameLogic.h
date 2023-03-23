


#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Balle.h"
#include "Level.h"
#include "BRIQUE.H"
#include "Plateforme.h"
#include "Controller.h"
#include <vector>
#include "Keyboard.h"
#include <iostream>
#include "Powerups.h"
#include <Windows.h>

class GameLogic {
private:
    std::vector<Balle*> _balls;
    std::vector<Powerups*> _powers;
    Level _level;
    LevelInfos _info;
    Plateforme _platform;
    char UI[RESMAX_Y][RESMAX_X];
    int _score;
    int _livesLeft;
    int maxSizeX;
    int maxSizeY;
    
 

    void checkCollisions(Controller& control);
public:
    GameLogic();
    GameLogic(LevelInfos _info);
    ~GameLogic();
    void update(Controller& c,bool accelmode);
    void draw(std::ostream &s);
    bool isGameOver();
    int getScoreInfo();
    Plateforme& getPlaform();
    void resetScore() { _score = 0; }

    friend std::istream& operator>>(std::istream& s, GameLogic &gl);
};


#endif
