#ifndef SnakeApplication_H
#define SnakeApplication_H

#include <string>

#include "BasicDisplay.h"
#include "App.h" 
#include "MainMenuDisplay.h"
#include "SnakeIcon.h"
#include "SnakeEngine.h"

class SnakeApplication : public App {
public:
    SnakeApplication() : title{"Snake"} {}

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif
