#include "Level.h"
#include "GameLoop.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(){

    Intro(std::cout);
    while (true)
    {
        GameLoop game;
        while (!game.over) {
            game.update();
            Sleep(SLEEP);
        }
    }
    return 0;
}
