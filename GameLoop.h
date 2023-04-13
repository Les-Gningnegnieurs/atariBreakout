

#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Canevas.h"
#include "Structs.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <QApplication>
#include <QTimer>
#include <QObject>
#include "mainWindow.h"



class GameLoop : public QObject {
    Q_OBJECT;
private:
    QMainWindow* _window;
    Canevas *_canevas;
    gameState _gameState;
    QTimer* timer;
    int bg = 0;

private slots:
    
public:
   

    GameLoop(QApplication* app, QObject* parent = nullptr);
    


};


#endif