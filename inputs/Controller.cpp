#include "Controller.h"

Joystick Controller::getJoystick(){


    return _joystick;
}

void Controller::setBargraph(int id, bool val){
    if(id >=0 && id < 10){
        if (_bargraph.status[id] != val)
        {
            _bargraph.status[id] = val;
            _outputChanged.bargraph = true;
        }
    }
}

void Controller::TurnOnLed(int id) {
    _leds[id].status = 1;
    _outputChanged.leds = true;
}

void Controller::TurnOffLed(int id) {
    _leds[id].status = 0;
    _outputChanged.leds = true;
}
bool Controller::statusLed(int id) {
    return _leds[id].status;
}

void Controller::setPower(bool mode){
    power.power = mode;
    _outputChanged.power = true;

}

void Controller::setLED(int id, int status, int R, int G, int B){
    if(id >= 0 && id < 2)
    {
        _leds[id].status = status;
        _leds[id].R = R;
        _leds[id].G = G;
        _leds[id].B = B;
        _outputChanged.leds = true;
    }
}

bool Controller::getButton(int id){
    if(id >= 0 && id < 4)
        return _buttons[id];
}

Accelerometre Controller::getAccelerometre(){
    return _accelerometre;
}


Controller::Controller(){
    _accelerometre.x = 0;
    _accelerometre.y = 0;
    _accelerometre.z = 0;
    _joystick.x = 0;
    _joystick.y = 0;
    for (int i = 0; i < 4; i++)
    {
        _buttons[i] = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        _leds[i].status = 0;
        _leds[i].R = 0;
        _leds[i].G = 0;
        _leds[i].B = 0;
        _outputChanged.leds = true;

    }
    for (int i = 0; i < 10; i++)
    {
        _bargraph.status[i] = 0;
        _outputChanged.bargraph = true;
    }
    power.power = false;
    _outputChanged.power = false;
}

Controller::~Controller(){}


void Controller::resetJoystick()
{
    _joystick.x = 0;
    _joystick.y = 0;
}

void Controller::resetButton()
{
    _buttons[0] = 0;
    _buttons[1] = 0;
    _buttons[2] = 0;
    _buttons[3] = 0;
}

void Controller::resetAccel()
{
    _accelerometre.x = 0;
    _accelerometre.y = 0;
    _accelerometre.z = 0;
}