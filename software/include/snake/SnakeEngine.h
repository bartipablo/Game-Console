#ifndef SnakeEngine_H
#define SnakeEngine_H

#include <thread>
#include <chrono>

#include "Area.h"
#include "Fruit.h"
#include "Snake.h"
#include "SnakeDisplay.h"
#include "SnakeScore.h"

#include "UserInput.h"
#include "Timer.h"
#include "BasicDisplay.h"

namespace snake {

class SnakeEngine {
    
public:
    SnakeEngine();

/**
 * Starts the game logic and the display.
 */
    void run();

private:
    Area area;

    Snake snake;

    Fruit fruit;

    Timer frameTimer;

    Score score;

    const static int FRAME_RATE {100};

    UserInput* userInput = UserInput::getInstance();

    bool isRunning;
};

}


#endif