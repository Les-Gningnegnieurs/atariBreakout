#ifndef KEYBOARD_H__
#define KEYBOARD_H__

#include "Controller.h"
#include "windows.h"

class Keyboard : public Controller{
public:
    void receiveInputs();
    void sendOutputs();
};

void Keyboard::receiveInputs(){
    //Controles de base 

    //Joystick X
    if((GetAsyncKeyState(VK_LEFT) || GetAsynckeyState('A')) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = 100;
    }
    else if((GetAsyncKeyState(VK_RIGHT) || GetAsynckeyState('D')) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = -100;
    }
    else{
        _joystick.x = 0;
    }

    //Joystick Y
    if((GetAsyncKeyState(VK_UP) || GetAsynckeyState('W')) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = -100;
    }
    else if((GetAsyncKeyState(VK_DOWN) || GetAsynckeyState('S')) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.y = 100;
    }
    else{
        _joystick.y = 0;
    }


    if(GetAsynckeyState(VK_SPACE) & 0x8000 )
    {
        //left arrow or A key held down 
        _buttons[0] = 1;
    }
    else{
        _button[0] = 0;
    }
};

void Keyboard::sendOutputs(){
    //do nothing
}
#endif