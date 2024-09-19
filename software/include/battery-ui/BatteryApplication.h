#ifndef BatteryApplication_H
#define BatteryApplication_H

#include "BasicDisplay.h"
#include "BatteryIcon.h"
#include "BatteryUI.h"
#include "MainMenuDisplay.h"
#include "App.h"

/**
 * Application to track the battery state
 * Displays in main menu
*/
class BatteryApplication : public App {

public:
    BatteryApplication() : title {"Battery"} {};

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif
