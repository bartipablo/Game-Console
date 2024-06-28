#ifndef SnakeApplication_H
#define SnakeApplication_H

#include <string>

#include "../app-menu/App.h" 
#include "../main-menu/MainMenuDisplay.h"
#include "SnakeIcon.h"
#include "SnakeEngine.h"

class SnakeApplication : public App {
public:
    TetrisApplication(MainMenuDisplay* menuDisplay) {
        title = "Snake";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        SnakeEngine* snakeEngine = new SnakeEngine();
        //snakeEngine->run();
        delete snakeEngine;
    }

    void display() override {
        Icon* snakeIcon = new SnakeIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*snakeIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete snakeIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;    
};

#endif
