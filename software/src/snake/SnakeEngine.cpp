#include "SnakeEngine.h"

namespace snake {

SnakeEngine::SnakeEngine() {
    area = new Area();
    snake = new Snake(Vector2D(10, 10), Direction::Right);
    fruit = new Fruit(Vector2D(0, 0));
    frameTimer = new Timer(FRAME_RATE);
    isRunning = false;
}

SnakeEngine::~SnakeEngine() {
    delete area;
    delete snake;
    delete fruit;
    delete frameTimer;
}

/*******************
 * MAIN GAME LOOP
********************/
void SnakeEngine::run() {
    isRunning = true;
    
    while (isRunning) {

        if (frameTimer->isExpired()) {

            if (userInput->isPressedJoysticDown()) {
                snake->changeDirection(Direction::Down);
            } else if (userInput->isPressedJoysticUp()) {
                snake->changeDirection(Direction::Up);
            } else if (userInput->isPressedJoysticLeft()) {
                snake->changeDirection(Direction::Left);
            } else if (userInput->isPressedJoysticRight()) {
                snake->changeDirection(Direction::Right);
            }

            snake->move();

            if (snake->isCollidingWithItself() || area->isOutOfBound(snake->getHeadPosition())) {
                isRunning = false;
            }

            if (snake->isAtPosition(fruit->getPosition())) {
                snake->grow();
                fruit->generateAtRandomPosition(snake, area);
            }

            frameTimer->reset();
        }
    }

}

}