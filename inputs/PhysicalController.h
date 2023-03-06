#ifndef PHYSICALCONTROLLER_H__
#define PHYSICALCONTROLLER_H__

#include "Controller.h"
#include <string>

#include "../lib/serial/SerialPort.hpp"
#include "../lib/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024

class PhysicalController : public Controller{
public:
    PhysicalController(std::string com);
    ~PhysicalController();
    bool receiveInputs();
    bool sendOutputs();
    void setCom(std::string com);

private:
    SerialPort * _arduino;
    std::string _com;
/*------------------------- Prototypes de fonctions -------------------------*/
    bool SendToSerial(SerialPort *arduino, json j_msg);
    bool RcvFromSerial(SerialPort *arduino, std::string &msg);
    bool ConnectionStatus();
};
#endif