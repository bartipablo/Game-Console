#ifndef SnakeEngine_H
#define SnakeEngine_H

#include "Area.h"
#include "Fruit.h"
#include "Snake.h"

#include "../utils/UserInput.h"
#include "../common/Timer.h"

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

    const int FRAME_RATE = 66;

    UserInput* userInput = UserInput::getInstance();

    bool isRunning;
};

}


#endif