#ifndef TetrisApplication_H
#define TetrisApplication_H

#include <string>

#include "App.h" 
#include "MainMenuDisplay.h"
#include "TetrisIcon.h"
#include "TetrisEngine.h"

class TetrisApplication : public App {
public:
    TetrisApplication(MainMenuDisplay* menuDisplay) {
        title = "Tetris";
        this->menuDisplay = menuDisplay;
    }

    void start() override {
        TetrisEngine* tetrisEngine = new TetrisEngine();
        tetrisEngine->run();
        delete tetrisEngine;
    }

    void display() override {
        Icon* tetrisIcon = new TetrisIcon();

        menuDisplay->clear();
        menuDisplay->drawIcon(*tetrisIcon);
        menuDisplay->drawTitle(title);
        menuDisplay->drawButtonInfo();

        delete tetrisIcon;
    }

private:
    std::string title;

    MainMenuDisplay* menuDisplay;    
};

#endif
