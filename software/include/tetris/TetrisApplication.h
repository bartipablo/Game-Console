#ifndef TetrisApplication_H
#define TetrisApplication_H

#include <string>

#include "BasicDisplay.h"
#include "App.h" 
#include "MainMenuDisplay.h"
#include "TetrisIcon.h"
#include "TetrisEngine.h"

class TetrisApplication : public App {
public:
    TetrisApplication() : title {"Tetris"} {}

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif
