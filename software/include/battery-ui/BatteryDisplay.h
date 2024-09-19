#ifndef WiFiDisplay_H
#define WiFiDisplay_H

#include <string>

#include "DigitalLCD.h"
#include "Color.h"
#include "BasicDisplay.h"

/**
 * Functions to display the batery status
 */

namespace batterydisplay {

    void drawLabeledValue(const char* label, float value, int x, int y, const char* unit);
    
    void drawVoltage(float voltage);

    void drawPercentage(float percentage);

    void drawTemperature(float temperature);
}

#endif