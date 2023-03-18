#include "Keyboard.h"

void Keyboard::receiveInputs(){
    //Controles de base 

    //Joystick X
    if(GetAsyncKeyState(VK_LEFT) & 0x8000 )
    {
        if (reversemode)
            _joystick.x = 1;
        //left arrow or A key held down 
        else
        _joystick.x = -1;
    }
    else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 )
    {
        if (reversemode)
            _joystick.x = -1;
        //left arrow or A key held down 
        else
        _joystick.x = 1;
    }
    else{
        _joystick.x = 0;
    }

    //Joystick Y
    if(GetAsyncKeyState(VK_UP) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = -1;
    }
    else if(GetAsyncKeyState(VK_DOWN) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = 1;
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

    if(GetAsyncKeyState(VK_RETURN) & 0x8000 )
    {
        //left arrow or A key held down 
        _buttons[1] = 1;
    }
    else{
        _buttons[1] = 0;
    }

    if(GetAsyncKeyState(VK_ESCAPE) & 0x8000 )
    {
        //left arrow or A key held down 
        _buttons[2] = 1;
    }
    else{
        _buttons[2] = 0;
    }
};

void Keyboard::sendOutputs(){
    //do nothing
}