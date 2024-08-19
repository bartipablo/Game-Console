#ifndef ServerMetadataInputDisplay_H
#define ServerMetadataInputDisplay_H

#include <string>

#include "Color.h"
#include "DigitalLCD.h"


namespace servermetadatain {

void drawIPv4AndPortInputInfo(Color colorIPv4, Color colorPort);

void drawInputIPv4(const std::string& IPv4);

void drawInputPort(const std::string& port);

}

#endif
