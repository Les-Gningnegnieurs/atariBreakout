#ifndef KEYBOARD_H__
#define KEYBOARD_H__

#include "Controller.h"
#include <Windows.h>

class Keyboard : public Controller{
public:
    void receiveInputs();
    void sendOutputs();
};
#endif