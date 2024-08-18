#ifndef ServerMetadataInputDisplay_H
#define ServerMetadataInputDisplay_H

#include <string>

#include "Color.h"
#include "DigitalLCD.h"

class ServerMetadataInputDisplay {
public:
    void clearScreen();

    void drawIPv4AndPortInputInfo(Color colorIPv4, Color colorPort);

    void drawInputIPv4(std::string IPv4);

    void drawInputPort(std::string port);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif
