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

void Controller::receiveInputs(){
    //connect to SATA and get string
    //TODO
    std::string incomming;

    //parse JSONString
    json inputs = json::parse(incomming);

    Joystick j;
    j.x = inputs["joystick"]["x"];
    j.y = inputs["joystick"]["y"];
    _joystick = j;

    Accelerometre a;
    a.deltaVitesse = inputs["accel"]["deltaS"];
    a.angleDeg = inputs["accel"]["angle"];
    _accelerometre = a;

    _buttons = inputs["buttons"];
}

void Controller::sendOutputs(){
    //build the json object

    json outputs = json{
    "Bargraph" : _bargraph.status,
    "Leds" : [
            {
                "R" : _leds[0].R,
                "G" : _leds[0].G,
                "B" : _leds[0].B
            },
            {
                "R" : _leds[1].R,
                "G" : _leds[1].G,
                "B" : _leds[1].B
            }
        ]
    };

    //envoyer l'objet Json par le port SATA
}