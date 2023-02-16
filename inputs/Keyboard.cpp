#include "Keyboard.h"

void Keyboard::receiveInputs(){
    //Controles de base 

    //Joystick X
    if(GetAsyncKeyState(VK_LEFT) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = -100;
    }
    else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = 100;
    }
    else{
        _joystick.x = 0;
    }

    //Joystick Y
    if(GetAsyncKeyState(VK_UP) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = -100;
    }
    else if(GetAsyncKeyState(VK_DOWN) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = 100;
    }
    else{
        _joystick.y = 0;
    }


    if(GetAsyncKeyState(VK_SPACE) & 0x8000 )
    {
        //left arrow or A key held down 
        _buttons[0] = 1;
    }
    else{
        _buttons[0] = 0;
    }
};

void Keyboard::sendOutputs(){
    //do nothing
}