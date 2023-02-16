#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include "../components/components.h"
#include <iostream>
#include "../lib/nlohmann/json.hpp"
using json = nlohmann::json;


class Controller{
protected:
    Joystick _joystick;
    Bargraph _bargraph;
    LedRGB _leds[2];
    bool _buttons[4];
    Accelerometre _accelerometre;

public:
    virtual void receiveInputs();
    virtual void sendOutputs();

    Controller();
    ~Controller();
    Joystick getJoystick();
    void setBargraph(int id, bool val);
    void setLED(int id, int R, int G, int B);
    bool getButton(int id);
    Accelerometre getAccelerometre();
};
#endif 