


#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Balle.h"
#include "Testballe.h"
#include "Level.h"
#include "BRIQUE.H"
#include "Plateforme.h"
#include "Controller.h"
#include <vector>
#include "Keyboard.h"
#include <iostream>
#include "Powerups.h"
#include <Windows.h>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

class GameLogic {
private:
    std::vector<Balle*> _balls;
    std::vector<Powerups*> _powers;
    Level *_level;
    LevelInfos _info;
    Plateforme _platform;
    MyRect* _plat;
    int _livesLeft;
    int maxSizeX;
    int maxSizeY;
    QGraphicsScene* _scene;
    Health* _vies1;
    Health* _vies2;
    Health* _vies3;
    Score* _score;
    QGraphicsRectItem* _rect;
    QGraphicsRectItem* array[20];
    QGraphicsPixmapItem* expand_img;
    QGraphicsPixmapItem* swap_img;
    bool waiting = false;
 

    void checkCollisions(Controller& control, bool accelmode);
public:
    GameLogic(QGraphicsScene* scene);
    GameLogic(LevelInfos _info, QGraphicsScene* scene);
    ~GameLogic();
    void update(Controller& c,bool accelmode);
    void update2();
    void draw();
    bool isGameOver();
    int getScoreInfo();
    Plateforme& getPlaform();
    void resetScore() { _score->resetScore(); } //a voir
    bool isCompleted();
    void init_virtual_bar();
    void setvirtualbargraph(Controller& c);
    void reset_virtual_bargraph();
    friend std::istream& operator>>(std::istream& s, GameLogic &gl);
    void powerup_img(std::string power, bool on=true);
};


#endif
