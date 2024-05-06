#ifndef ServerMetadataInputDisplay_H
#define ServerMetadataInputDisplay_H

#include <string>

#include "../../common/Color.h"
#include "../../utils/DigitalLCD.h"

class ServerMetadataInputDisplay {
public:
    void clearScreen();

    void drawIPv4AndPortInputInfo(Color colorIPv4, Color colorPort);

    void drawInputIPv4(std::string IPv4);

    void drawInputPort(std::string port);

    void drawCommunicate(std::string message, Color color, bool blocking);


private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();    
};


#endif
