#ifndef SnakeEngine_H
#define SnakeEngine_H

#include "Area.h"
#include "Fruit.h"
#include "Snake.h"
#include "SnakeDisplay.h"

#include "../utils/UserInput.h"
#include "../common/Timer.h"
#include "../common/BasicDisplay.h"

namespace snake {

class SnakeEngine {
    
public:
    SnakeEngine();

    ~SnakeEngine();

    void run();

private:
    Area* area;

    Snake* snake;

    Fruit* fruit;

    Timer* frameTimer;

    const int FRAME_RATE = 100;

    SnakeDisplay* snakeDisplay;

    BasicDisplay* basicDisplay;

    UserInput* userInput = UserInput::getInstance();

    bool isRunning;
};

}


#endif