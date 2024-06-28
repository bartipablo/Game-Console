#include "SnakeEngine.h"

namespace snake {

SnakeEngine::SnakeEngine() {
    area = new Area();
    snake = new Snake(Vector2D(10, 10), Direction::Right);
    fruit = new Fruit(Vector2D(0, 0));
    SnakeDisplay = new SnakeDisplay();
    frameTimer = new Timer(FRAME_RATE);
    isRunning = false;
}

SnakeEngine::~SnakeEngine() {
    delete area;
    delete snake;
    delete fruit;
    delete frameTimer;
    delete SnakeDisplay;
}

/*******************
 * MAIN GAME LOOP
********************/
void SnakeEngine::run() {
    isRunning = true;
    
    snakeDisplay->drawSnake(snake);

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

            if (snake->getHeadPosition() == fruit->getPosition()) {
                snake->grow();
                fruit->generateAtRandomPosition(snake, area);
                snakeDisplay->drawFruit(fruit);
            }

            frameTimer->reset();

            snakeDisplay->updateSnake(snake);
        }
    }

}

}