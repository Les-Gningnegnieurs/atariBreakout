#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include "components/components.h"
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Controller{
private:
    Joystick _joystick;
    Bargraph _bargraph;
    LedRGB _leds[2];
    bool _buttons[4];
    Accelerometre _accelerometre;

public:
    virtual void receiveInputs();
    virtual void sendOutputs();

    Joystick getJoystick();
    void setBargraph(int id, bool val);
    void setLED(int id, int R, int G, int B);
    bool getButton(int id);
    Accelerometre getAccelerometre();
};
#endif 