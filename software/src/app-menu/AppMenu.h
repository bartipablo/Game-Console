#ifndef AppMenu_H
#define AppMenu_H

#include <vector>
#include "Arduino.h"

#include "App.h"
#include "../utils/InputBlocking.h"
#include "../utils/UserInput.h"

/**
 * 
 * 
 */
class AppMenu {
public:
    AppMenu(std::vector<App*> apps);

    ~AppMenu();

    void setLoopedMenu(bool loopedMenu);

    void setBlockExit(bool blockExit);

    void start();

private:
    void previousApplication();

    void nextApplication();

    int currentApplicationIndex = 0;

    bool blockExit = false;

    bool loopedMenu = false;

    InputBlocking* inputBlocking;

    UserInput* userInput;

    App* currentApplication;

    std::vector<App*> appList;
};

#endif