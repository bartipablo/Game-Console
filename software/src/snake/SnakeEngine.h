#ifndef SnakeEngine_H
#define SnakeEngine_H

#include <thread>
#include <chrono>

#include "Area.h"
#include "Fruit.h"
#include "Snake.h"
#include "SnakeDisplay.h"
#include "Score.h"

#include "../utils/UserInput.h"
#include "../common/Timer.h"
#include "../common/BasicDisplay.h"

namespace snake {

class SnakeEngine {
    
public:
    SnakeEngine();

    ~SnakeEngine();

/**
 * Starts the game logic and the display.
 */
    void run();

private:
    Area* area;

    Snake* snake;

    Fruit* fruit;

    Timer* frameTimer;

    Score* score;

    const int FRAME_RATE = 100;

    SnakeDisplay* snakeDisplay;

    BasicDisplay* basicDisplay;

    UserInput* userInput = UserInput::getInstance();

    bool isRunning;
};

}


#endif