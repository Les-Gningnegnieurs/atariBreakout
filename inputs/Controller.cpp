#include "Controller.h"

Joystick Controller::getJoystick(){


    return _joystick;
}

void Controller::setBargraph(int id, bool val){
    if(id >=0 && id < 10){
        _bargraph.status[id] = val;
        _outputChanged.bargraph = true;
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


Controller::Controller(){}

Controller::~Controller(){}



