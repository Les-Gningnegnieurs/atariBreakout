#include "inputs/Keyboard.h"

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
}