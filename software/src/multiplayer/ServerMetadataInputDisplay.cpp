#include "ServerMetadataInput.h"

namespace servermetadatain {

void drawIPv4AndPortInputInfo(Color colorIPv4, Color colorPort) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setCursor(0, 10);
    display->setTextColor(Color::WHITE_);
    display->setTextSize(2);
    display->println("Enter server IP and port:");
    display->println("");
    display->setTextColor(colorIPv4.getColorRGB565());
    display->println("IPv4:");
    display->println("");
    display->setTextColor(colorPort.getColorRGB565());
    display->println("Port:");
}


void drawInputIPv4(const std::string& IPv4) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextColor(Color::GREEN_); 

    display->setTextSize(2);
    display->fillRect(70, 42, 320, 20, Color::BLACK_);
    display->setCursor(70, 42);
    display->print(IPv4.c_str());
}


void drawInputPort(const std::string& port) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextColor(Color::GREEN_); 

    display->setTextSize(2);
    display->fillRect(70, 72, 320, 20, Color::BLACK_);
    display->setCursor(70, 72);
    display->print(port.c_str());
}

}