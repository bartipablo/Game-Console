#ifndef SnakeApplication_H
#define SnakeApplication_H

#include <string>

#include "../app-menu/App.h" 
#include "../main-menu/MainMenuDisplay.h"
#include "SnakeIcon.h"
#include "SnakeEngine.h"

namespace snake {

class SnakeApplication : public App {
public:
    SnakeApplication(MainMenuDisplay* menuDisplay) {
        title = "Snake";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        snake::SnakeEngine* snakeEngine = new snake::SnakeEngine();
        snakeEngine->run();
        delete snakeEngine;
    }

    void display() override {
        Icon* snakeIcon = new snake::SnakeIcon();

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

}

#endif
