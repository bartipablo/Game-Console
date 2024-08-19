#ifndef BasicDisplay_H
#define BasicDisplay_H

#include <string>

#include "DigitalLCD.h"
#include "Color.h"

/**
 * This namespace should contain basic and common functions for displaying images in many applications.
*/
namespace basicdisplay {

void clearScreen();

void drawInfo(std::string message, std::string title);

void drawInfo(std::string message, std::string title, Color messageColor, Color titleColor);

void drawBelowMessage(std::string message);

void drawBelowMessage(std::string message, Color color);

};


#endif