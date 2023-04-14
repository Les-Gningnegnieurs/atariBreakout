#ifndef KEYBOARD_H__
#define KEYBOARD_H__

#include "Controller.h"
#include <Windows.h>


class Keyboard : public Controller{
public:
    Keyboard() : Controller() {}
    bool receiveInputs();
    bool sendOutputs();
    bool ConnectionStatus() { return true; };
   /* void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);*/
};
#endif