#ifndef WiFiApplication_H
#define WiFiApplication_H

#include "BasicDisplay.h"
#include "MainMenuDisplay.h"
#include "App.h" 
#include "WiFiUI.h"
#include "WiFiIcon.h"

/**
 * Application to manage the WiFi connection
 * Displays in main menu
*/
class WiFiApplication : public App {
public:
    WiFiApplication() : title {"WiFi"} {};

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif
