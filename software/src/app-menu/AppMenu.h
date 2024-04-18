#ifndef AppMenu_H
#define AppMenu_H

#include <vector>
#include "Arduino.h"

#include "App.h"
#include "AppDisplay.h"
#include "../utils/InputBlocking.h"
#include "../utils/UserInput.h"

/**
 * 
 * 
 */
class AppMenu {
public:
    template<typename... Args>
    AppMenu(AppDisplay* appDisplay, Args&&... apps) : 
        appDisplay(appDisplay), 
        appList{std::forward<Args>(apps)...} {
            inputBlocking = new InputBlocking();
        };

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

    UserInput* userInput = UserInput::getInstance();

    App* currentApplication;

    AppDisplay* appDisplay;

    std::vector<App*> appList;
};

#endif