#include "BatteryUI.h"


void BatteryUI::run() {
    basicdisplay::clearScreen();
    basicdisplay::drawBelowMessage("Press any key to exit");

    refreshReadings();
    
    delay(500);

    while (true) {
        if (loopCounter > 50) {
            refreshReadings();
            loopCounter = 0;
        }

        if (userInput->isPressedLeftButton() || userInput->isPressedRightButton()) {
            return;
        }

        loopCounter++;
        delay(20);
    }
}


void BatteryUI::refreshReadings() {
    using namespace basicdisplay;
    using namespace batterydisplay;

    float voltage = battery->getVoltage();
    float percentage = battery->getPercentCharged();
    float temperature = battery->getTemperature();

    clearValues();

    drawVoltage(voltage);
    drawPercentage(percentage);
    drawTemperature(temperature);

}