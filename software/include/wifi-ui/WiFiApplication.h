#ifndef WiFiApplication_H
#define WiFiApplication_H

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
    WiFiApplication(MainMenuDisplay* menuDisplay);

    void start() override;

    void display() override;

private:
    std::string title;
    MainMenuDisplay* menuDisplay;
};

#endif
