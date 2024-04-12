#ifndef Menu_H
#define Menu_H

#include <vector>

#include "Application.h"
#include "./paint/PaintApplication.h"
#include "./tetris/TetrisApplication.h"
#include "MenuDisplay.h"
#include "Icon.h"
#include "../utils/UserInput.h"
#include "../utils/InputBlocking.h"

class Menu {

public:
    Menu();

    ~Menu();

    void start();

private:
    void nextApplication();

    void previousApplication();

    MenuDisplay* menuDisplay;

    UserInput* userInput = UserInput::getInstance();

    InputBlocking* inputBlocking;

    void displayApplication(Application* application);

    int currentApplicationIndex = 0;

    std::vector<Application*> applications;

    Application* currentApplication;

    int applicationsQuantity;
};

#endif