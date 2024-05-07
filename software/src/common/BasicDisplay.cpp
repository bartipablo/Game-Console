#include "BasicDisplay.h"

void BasicDisplay::clearScreen() {
    display->fillScreen(Color::BLACK_);
}


void BasicDisplay::drawInfo(std::string message, std::string title) {
    drawInfo(message, title, Color::WHITE_, Color::WHITE_);    
}


void BasicDisplay::drawInfo(std::string message, std::string title, Color messageColor, Color titleColor) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(2);
    display->fillRect(0, 90, 320, 50, Color::GRAY_);
    display->setCursor(0, 100);
    display->setTextColor(messageColor.getColorRGB565()); 
    display->print(message.c_str());

    display->setTextSize(3);
    display->setCursor(100, 10);
    display->setTextColor(titleColor.getColorRGB565()); 
    display->print(title.c_str());

    display->setRotation(originalRotation);    
}


void BasicDisplay::drawBelowMessage(std::string message) {
        drawBelowMessage(message, Color::WHITE_);
}


void BasicDisplay::drawBelowMessage(std::string message, Color color) {
    uint8_t originalRotation = display->getRotation();
    display->setRotation(3); 

    display->setTextSize(1);
    
    uint16_t textWidth = message.length() * 6; 

    int16_t startX = (320 - textWidth) / 2;
    int16_t startY = 200; 
    
    display->setCursor(startX, startY);
    display->setTextColor(color.getColorRGB565());
    display->print(message.c_str());

    display->setRotation(originalRotation);    
}