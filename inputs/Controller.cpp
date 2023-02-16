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

    //parse JSONString with nlohmann library
    json inputs = json::parse(incomming);

    Joystick j;
    j.x = inputs["joystick"]["x"];
    j.y = inputs["joystick"]["y"];
    _joystick = j;

    Accelerometre a;
    a.deltaVitesse = inputs["accel"]["deltaS"];
    a.angleDeg = inputs["accel"]["angle"];
    _accelerometre = a;

    for(int i = 0; i < 4; i++){
        _buttons[i] = (bool)inputs["buttons"][i];
    }
}

void Controller::sendOutputs(){
    //build the json object with the nlohmann library and serialize it
    json outputs;
    outputs["Bargraph"] = _bargraph.status;
    outputs["Leds"] = json::array();
    for(int i = 0; i < 2; i++){
        json led;
        led["R"] = _leds[i].R;
        led["G"] = _leds[i].G;
        led["B"] = _leds[i].B;
        outputs["Leds"].push_back(led);
    }

    //serialize the json object to string
    std::string out = outputs.dump();

    //send the string to the SATA
    //TODO
}

Controller::Controller(){}

Controller::~Controller(){}