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
                snake->setDirection(Direction::Down);
            } else if (userInput->isPressedJoysticUp()) {
                snake->setDirection(Direction::Up);
            } else if (userInput->isPressedJoysticLeft()) {
                snake->setDirection(Direction::Left);
            } else if (userInput->isPressedJoysticRight()) {
                snake->setDirection(Direction::Right);
            }

            snake->move();

            if (snake->isCollidingWithItself() || area->isOutOfBound(snake->getHead())) {
                isRunning = false;
            }

            if (snake->isAtPosition(fruit->getPosition())) {
                snake->grow();
                fruit->generateAtRandomPosition(snake, area);
            }

            frameTimer->restart();
        }
    }

}

}