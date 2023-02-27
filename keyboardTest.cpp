#include "Level.h"
#include "GameLoop.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    GameLoop game;
    game.Start();
    while(true){
        game.update();
        Sleep(150);
    }
    return 0;
}
