

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "menu.h"
#include "Canevas.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <QApplication>
#include <QTimer>
#include <QObject>
#include "inputs/Keyboard.h"
#include "inputs/PhysicalController.h"
#include "mainWindow.h"



class GameLoop : public QObject {
    Q_OBJECT;
private:
    MainWindow* _window;
    Canevas *_canevas;
    Menu _menu;
    gameState _gameState;
    QTimer* timer;
    int bg = 0;

private slots:
    void MainGameLoop();
    
public:
    Controller* _controller;

    bool over;
    GameLoop(QApplication* app, QObject* parent = 0);
    void Start();
    void Stop();
    void Pause();
    void update();
    void GameOver();
    void Restart();
    void draw();
    void loadFile();
    void startGameLoop();
    void stopGameLoop();


};


#endif