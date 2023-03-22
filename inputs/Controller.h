#ifndef CONTROLLER_H__
#define CONTROLLER_H__

#include "../components/components.h"
#include <iostream>



class Controller{
protected:
    Joystick _joystick;
    bool _buttons[4];
    Accelerometre _accelerometre;
    Bargraph _bargraph;
    LedRGB _leds[2];
    OuputChanged _outputChanged;
    bool _reversemode = false;
    Powermanette power;

public:
    virtual bool receiveInputs() = 0;
    virtual bool sendOutputs() = 0;

    Controller();
    ~Controller();
    Joystick getJoystick();
    void setBargraph(int id, bool val);
    void setLED(int id, int status, int R, int G, int B);
    bool getButton(int id);
    Accelerometre getAccelerometre();
    void setReverse(bool mode) { _reversemode = mode; }
    void setPower(bool mode);

    void TurnOffLed(int id);
    void TurnOnLed(int id);
    bool statusLed(int id);
};
#endif 