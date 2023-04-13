#include "PhysicalController.h"

PhysicalController::PhysicalController(std::string com){
    _com = com;
    _arduino = new SerialPort(_com.c_str(), BAUD);
    _outputChanged.power = true;
    power.power = true;
    for (int i = 0; i < 10; i++)
    {
        _bargraph.status[i] = 0;
    }
    sendOutputs();
}

PhysicalController::~PhysicalController() {
    _outputChanged.power = true;
    power.power = false;
    sendOutputs();
}

bool PhysicalController::ConnectionStatus(){
    return _arduino->isConnected();
}

void PhysicalController::setCom(std::string com){
    _com = com;
    _arduino = new SerialPort(_com.c_str(), BAUD);
}


bool PhysicalController::sendOutputs() {
    //si aucun changement, ne rien envoyer
    json j_msg_send;
    if (_outputChanged.power)
    {
        j_msg_send["s"] = power.power;
        _outputChanged.power = false;
    }

    //build json message with only the changed outputs
    //{"b" : [0..9]} (0/1)
    if (_outputChanged.bargraph){
        j_msg_send["b"] = _bargraph.status;
        _outputChanged.bargraph = false;
    }

    //{"l" : [[0/1, R, G, B], [0/1, R, G, B]]}
    if(_outputChanged.leds){
        int temp[6] = { _leds[0].R, _leds[0].G, _leds[0].B, _leds[1].R, _leds[1].G, _leds[1].B };
        if (!_leds[0].status) {
            temp[0] = 0;
            temp[1] = 0;
            temp[2] = 0;
        }

        if (!_leds[1].status) {
            temp[3] = 0;
            temp[4] = 0;
            temp[5] = 0;
        }

        j_msg_send["l"] = temp;
        _outputChanged.leds = false;
    }

    if(j_msg_send==json::value_t::null){
        j_msg_send["t"] = 0;
        SendToSerial(_arduino, j_msg_send);
    }
    else
        return SendToSerial(_arduino, j_msg_send);
}

bool PhysicalController::receiveInputs(){

    json j_msg_rcv;
    std::string raw_msg;
    // Reception d'un message venant du Arduino
    if(!RcvFromSerial(_arduino, raw_msg)){
        return false;
    }


    // Impression du message de l'Arduino si valide
    if(raw_msg.size()>0){
    // Transfert du message en json
        if (raw_msg.find('{') == std::string::npos || raw_msg.find('}') == std::string::npos)
            return false;

        if (raw_msg.size() > 10) {
            raw_msg = raw_msg.substr(raw_msg.find_last_of('{'), raw_msg.find_last_of('}') + 1);
        }
        
        if (raw_msg.find('{') != std::string::npos && raw_msg.find('}') != std::string::npos)
            j_msg_rcv = json::parse(raw_msg);
        else
            return false;
    }
    else{
        return false;
    }

    //parse the updated inputs

    //a vérifier
    //{"j": [x,y]} //map 0..100
    if(j_msg_rcv["j"] != json::value_t::null){
        //update joystick values

        _joystick.x = j_msg_rcv["j"][0] != 0 ? j_msg_rcv["j"][0] > 0 ? 1 : -1 : 0;
        _joystick.y = j_msg_rcv["j"][1] != 0 ? j_msg_rcv["j"][1] > 0 ? 1 : -1 : 0;

        if (_reversemode)
        {
            _joystick.x = -1 * _joystick.x;
        }
    }

    //Reset les bouttons
    _buttons[0] = 0;
    _buttons[1] = 0;
    _buttons[2] = 0;
    _buttons[3] = 0;

    //{"b": [b1,b2,b3,b4]} (0/1)
    if(j_msg_rcv["b"] != json::value_t::null){
        _buttons[0] = j_msg_rcv["b"][0] == 1;
        _buttons[1] = j_msg_rcv["b"][1] == 1;
        _buttons[2] = j_msg_rcv["b"][2] == 1;
        _buttons[3] = j_msg_rcv["b"][3] == 1;
    }

    //{"a" : [x,y,z]} 
    if(j_msg_rcv["a"] != json::value_t::null){
        //update accelerometer values
        _accelerometre.x = j_msg_rcv["a"][0] != 0 ? j_msg_rcv["a"][0] > 0 ? 1 : -1 : 0;
        if (_reversemode)
            _accelerometre.x *= -1;
        _accelerometre.y = j_msg_rcv["a"][1];
        _accelerometre.z = j_msg_rcv["a"][2];
    }

    if (j_msg_rcv["r"] != json::value_t::null) {
        _rand = j_msg_rcv["r"];
    }


    return true;
    
}

/*---------------------------Definition de fonctions ------------------------*/
bool PhysicalController::SendToSerial(SerialPort *arduino, json j_msg){
    // Return 0 if error
    std::string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


bool PhysicalController::RcvFromSerial(SerialPort *arduino, std::string &msg){
    // Return 0 if error
    // Message output in msg
    std::string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string

    // Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort1(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

 

    return true;
}
