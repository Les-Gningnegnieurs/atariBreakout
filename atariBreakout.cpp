//#include "Level.h"
#include "GameLoop.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include <QThread>
#include <QTimer>
#include "SelectLevel.h"

using namespace std;
int main(int argc, char** argv){

    QApplication a(argc, argv);
    QWidget* window = new QWidget();

    SelectLevel* level = new SelectLevel(window);
    
    //Intro(std::cout);
    //GameLoop* game = new GameLoop();

     //game->Start();
     //game->update2(); //renomer la méthode pour Focus()
    window->resize(1000,800 );
    window->show();
    return a.exec();
}
