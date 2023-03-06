#include "PhysicalController.h"

PhysicalController::PhysicalController(std::string com){
    _com = com;
    _arduino = new SerialPort(_com.c_str(), BAUD);
}

bool PhysicalController::ConnectionStatus(){
    return _arduino->isConnected();
}

void PhysicalController::setCom(std::string com){
    _com = com;
    _arduino = new SerialPort(_com.c_str(), BAUD);
}


bool PhysicalController::sendOutputs(){
    //si aucun changement, ne rien envoyer
    json j_msg_send;

    //build json message with only the changed outputs
    //{"b" : [0..9]} (0/1)
    if(_outputChanged.bargraph){
        j_msg_send["b"] = _bargraph.status;
    }

    //{"l" : [l1,l2]} (0/1)
    //{"l" : [[0/1, R, G, B], [0/1, R, G, B]]}
    if(_outputChanged.leds){
        j_msg_send["l"] = {{_leds[0].status, _leds[0].R, _leds[0].G, _leds[0].B}, {_leds[1].status, _leds[1].R, _leds[1].G, _leds[1].B}};
    }

    if(j_msg_send==json::value_t::null){
        return false;
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
        j_msg_rcv = json::parse(raw_msg);
    }
    else{
        return false;
    }

    //Verification du message (null ou pas)
    if (j_msg_rcv==json::value_t::null)
    {
        return false;
    }
    else{
        //parse the updated inputs

        //a vérifier
        //{"j": [x,y]} //map 0..100
        if(j_msg_rcv["j"] != json::value_t::null){
            //update joystick values
            _joystick.x = j_msg_rcv["j"][0];
            _joystick.y = j_msg_rcv["j"][1];
        }

        //{"b": [b1,b2,b3,b4]} (0/1)
        if(j_msg_rcv["b"] != json::value_t::null){
            _buttons[0] = j_msg_rcv["b"][0];
            _buttons[1] = j_msg_rcv["b"][1];
            _buttons[2] = j_msg_rcv["b"][2];
            _buttons[3] = j_msg_rcv["b"][3];
        }

        //{"a" : [x,y,z]} 
        if(j_msg_rcv["a"] != json::value_t::null){
            //update accelerometer values
            _accelerometre.x = j_msg_rcv["a"][0];
            _accelerometre.y = j_msg_rcv["a"][1];
            _accelerometre.z = j_msg_rcv["a"][2];
        }

        return true;
    }
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
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*  
    while(msg.back()!='\n'){
        if(msg.size()>MSG_MAX_SIZE){
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }
*/

    // Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    //msg.pop_back(); //remove '/n' from string

    return true;
}
