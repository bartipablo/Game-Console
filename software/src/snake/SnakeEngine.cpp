#include "SnakeEngine.h"

namespace snake {

SnakeEngine::SnakeEngine() {
    area = new Area();
    snake = new Snake(Vector2D(10, 10), Direction::Right);
    fruit = new Fruit(Vector2D(0, 0));
    snakeDisplay = new SnakeDisplay();
    frameTimer = new Timer(FRAME_RATE);
    score = new Score();
    isRunning = false;
}

SnakeEngine::~SnakeEngine() {
    delete area;
    delete snake;
    delete fruit;
    delete frameTimer;
    delete snakeDisplay;
    delete score;
}

/*******************
 * MAIN GAME LOOP
********************/
void SnakeEngine::run() {
    isRunning = true;

    fruit->generateAtRandomPosition(snake, area);
    
    basicdisplay::clearScreen();
    snakeDisplay->drawSnake(snake);
    snakeDisplay->drawFruit(fruit);
    snakeDisplay->drawRightBoundary();
    snakeDisplay->drawScoreTitle();
    snakeDisplay->drawScore(score);

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
            } else if (userInput->isPressedRightButton()) {
                isRunning = false;
            }

            snake->move();

            if (snake->isCollidingWithItself() || area->isOutOfBound(snake->getHeadPosition())) {
                isRunning = false;
            }

            bool fruitEaten = false;

            if (snake->getHeadPosition() == fruit->getPosition()) {
                fruitEaten = true;
                snake->grow();

                bool generatedNewFruit = fruit->generateAtRandomPosition(snake, area);

                if (!generatedNewFruit) {
                    isRunning = false;
                    continue;
                }

                score->incrementScore();
                snakeDisplay->drawScore(score);
            }

            frameTimer->reset();

            snakeDisplay->updateSnake(snake);

            if (fruitEaten) {
                snakeDisplay->drawFruit(fruit);
            }
        }
    }

    basicdisplay::clearScreen();
    snakeDisplay->drawGameOver(score);

    std::chrono::milliseconds duration(3000);
    std::this_thread::sleep_for(duration);
}

}