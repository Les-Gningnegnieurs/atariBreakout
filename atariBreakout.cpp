#include "GameLoop.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include "SelectLevel.h"
#include <QDebug>

using namespace std;
int main(int argc, char** argv) {

    QApplication a(argc, argv);

   // SelectLevel* level = new SelectLevel;
    //Intro(std::cout);
     GameLoop* game = new GameLoop(&a);

   /* game->Start();
    game->update2();*/ //renomer la m�thode pour Focus()
    
    return a.exec();
}
