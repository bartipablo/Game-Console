#include "BatteryDisplay.h"

namespace batterydisplay {


void drawLabeledValue(const char* label, float value, int x, int y, const char* unit) {
    Arduino_ILI9341* display = DigitalLCD::getInstance();
    
    display->setTextSize(2);
    display->setCursor(x, y);
    display->setTextColor(Color::WHITE_);
    
    char valueStr[10];
    dtostrf(value, 5, 2, valueStr);

    display->print(label);
    display->setCursor(x + 100, y); // Adjust X offset if needed
    display->print(valueStr);
    display->print(unit);
}

void drawVoltage(float voltage) {
    drawLabeledValue("Voltage: ", voltage, 10, 20, " [V]");
}

void drawPercentage(float percentage) {
    drawLabeledValue("Percentage: ", percentage, 10, 50, " [%]");
}

void drawTemperature(float temperature) {
    drawLabeledValue("Temperature: ", temperature, 10, 80, " [°C]");
}

}
