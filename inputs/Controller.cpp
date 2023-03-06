#include "Controller.h"

Joystick Controller::getJoystick(){
    return _joystick;
}

void Controller::setBargraph(int id, bool val){
    if(id >=0 && id < 10)
        _bargraph.status[id] = val;
}

void Controller::setLED(int id, int R, int G, int B){
    if(id >= 0 && id < 2)
    {
        _leds[id].R = R;
        _leds[id].G = G;
        _leds[id].B = B;
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

}

Controller::~Controller(){}



