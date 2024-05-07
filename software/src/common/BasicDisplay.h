#ifndef BasicDisplay_H
#define BasicDisplay_H

#include <string>

#include "../utils/DigitalLCD.h"
#include "../common/Color.h"

/**
 * This class should contain basic and common functions for displaying images in many applications.
*/
class BasicDisplay {

public:
    void clearScreen();

    void drawInfo(std::string message, std::string title);

    void drawInfo(std::string message, std::string title, Color messageColor, Color titleColor);

    void drawBelowMessage(std::string message);

    void drawBelowMessage(std::string message, Color color);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};


#endif