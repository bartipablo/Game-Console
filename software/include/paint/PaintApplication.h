#ifndef PaintApplication_H
#define PaintApplication_H

#include <string>

#include "BasicDisplay.h"
#include "App.h" 
#include "MainMenuDisplay.h"
#include "PaintIcon.h"
#include "PaintEngine.h"

class PaintApplication : public App {
public:
    PaintApplication() : title {"Paint"} {}

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif