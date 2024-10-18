#ifndef BatteryUI_H
#define BatteryUI_H

#include "Battery.h"
#include "AppMenu.h"
#include "UserInput.h"
#include "BatteryDisplay.h"


/**
 * User interface to track the battery status
 */
class BatteryUI {

public:
    BatteryUI() {}

/**
 * Run the battery user interface
*/
    void run();

private:
    int loopCounter = 0;

    void refreshReadings();

    Battery* battery = Battery::getInstance();

    UserInput* userInput = UserInput::getInstance();
};

#endif
