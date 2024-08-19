#ifndef PongApplication_H
#define PongApplication_H

#include <string>
#include <regex>

#include "BasicDisplay.h"
#include "App.h" 
#include "MainMenuDisplay.h"
#include "PongIcon.h"
#include "ServerMetadataInput.h"
#include "ConsoleClient.h"


class PongApplication : public App {
public:
    PongApplication() : title {"Pong (Multi)"} {}

    void start() override;

    void display() override;

private:
    std::string title;
};

#endif