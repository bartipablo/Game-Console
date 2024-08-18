#include "BasicDisplay.h"

namespace basicdisplay {

void clearScreen() {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->fillScreen(Color::BLACK_);
}


void drawInfo(std::string message, std::string title) {
    drawInfo(message, title, Color::WHITE_, Color::WHITE_);    
}


void drawInfo(std::string message, std::string title, Color messageColor, Color titleColor) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(2);
    display->fillRect(0, 90, 320, 50, Color::GRAY_);
    display->setCursor(0, 100);
    display->setTextColor(messageColor.getColorRGB565()); 
    display->print(message.c_str());

    display->setTextSize(3);
    display->setCursor(100, 10);
    display->setTextColor(titleColor.getColorRGB565()); 
    display->print(title.c_str());
}


void drawBelowMessage(std::string message) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    drawBelowMessage(message, Color::WHITE_);
}


void drawBelowMessage(std::string message, Color color) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();

    display->setTextSize(1);
    
    uint16_t textWidth = message.length() * 6; 

    int16_t startX = (320 - textWidth) / 2;
    int16_t startY = 200; 
    
    display->setCursor(startX, startY);
    display->setTextColor(color.getColorRGB565());
    display->print(message.c_str());
}

}