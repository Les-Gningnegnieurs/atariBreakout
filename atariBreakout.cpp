#include "Level.h"
#include "GameLoop.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QThread>
#include <QTimer>

using namespace std;
int main(int argc, char** argv){

    QApplication a(argc, argv);


    //Intro(std::cout);
    GameLoop* game = new GameLoop();

    game->Start();
    game->update2(); //renomer la méthode pour Focus()
    
    return a.exec();
}
