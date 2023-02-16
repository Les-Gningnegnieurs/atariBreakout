#include "inputs/Keyboard.h"
/*
int main(){
    Keyboard k;

    while(true){
        k.receiveInputs();
        //print status in one line 
        std::cout << "Joystick: " << k.getJoystick().x << " " << k.getJoystick().y << " ";
        std::cout << "Buttons: " << k.getButton(0) << " ";
        std::cout << std::endl;
        
    }
    return 0;
}*/
#include "Level.h"
#include <fstream>
#include <iostream>

using namespace std;
int main() {
    Level _lev;
    fstream myfile;
    myfile.open("../ataribreakout/testNiveau.txt", ios::in);
    if (!myfile)
        myfile.close();
    else {
        myfile >> _lev;
    }
    myfile.close();
    _lev.draw();
    return 0;
}