#include "Level.h"
#include "GameLoop.h"
#include <fstream>
#include <iostream>
#include <QApplication>
#include "SelectLevel.h"
#include <QDebug>
#include "GameOver.h"
#include <QGraphicsView>

using namespace std;
int main(int argc, char** argv) {
    QApplication a(argc, argv);

    //GameOver scene(&a, nullptr);
    //QGraphicsView* view = new QGraphicsView(&scene);
    //view->setFixedSize(1200, 800); // Définition de la taille fixe de la vue
    //view->show();


   // SelectLevel* level = new SelectLevel;
    //Intro(std::cout);
   GameLoop* game = new GameLoop(&a);

   /* game->Start();
    game->update2();*/ //renomer la m�thode pour Focus()
    
    return a.exec();
}
