#include "Keyboard.h"
#include <QDebug>

bool Keyboard::receiveInputs(){
    //Controles de base 

    //Joystick X
    if(GetAsyncKeyState(VK_LEFT) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = -1;
    }
    else if(GetAsyncKeyState(VK_RIGHT) & 0x8000 )
    {
        //left arrow or A key held down 
        _joystick.x = 1;
        qDebug() << "Left key pressed";

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

    if (_reversemode)
    {
        _joystick.x = -1 * _joystick.x;
    }

    return true;
};

bool Keyboard::sendOutputs(){
    //do nothing
    return false;
}

//void Keyboard::keyPressEvent(QKeyEvent* event) {
//    if (event->key() == Qt::Key_Left)
//        _joystick.x = -1;
//    else if (event->key() == Qt::Key_Right)
//        _joystick.x = 1;
//    else if (event->key() == Qt::Key_Up)
//        _joystick.y = -1;
//    else if (event->key() == Qt::Key_Down)
//        _joystick.y = 1;
//}
//void Keyboard::keyReleaseEvent(QKeyEvent* event) 
//{
//    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right)
//        _joystick.x = 0;
//    else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
//        _joystick.y = 0;
//
//    // Handle button events
//    // ...
//}
