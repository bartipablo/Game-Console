#ifndef WiFiApplication_H
#define WiFiApplication_H

#include "../app-menu/App.h" 
#include "WiFiUI.h"
#include "WiFiIcon.h"

class WiFiApplication : public App {
public:        
    WiFiApplication(MainMenuDisplay* menuDisplay) {
        title = "WiFi";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        WiFiUI* wifiUI = new WiFiUI();
        wifiUI->run();
        delete wifiUI;
    }

    void display() override {
        Icon* wifiIcon = new WiFiIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*wifiIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete wifiIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;
};

#endif