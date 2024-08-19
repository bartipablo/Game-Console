#include "SnakeEngine.h"

namespace snake {


SnakeEngine::SnakeEngine() 
: snake{Vector2D{10, 10}, Direction::Right}, fruit{Vector2D{0, 0}}, frameTimer{FRAME_RATE}, isRunning{false} {}


/*******************
 * MAIN GAME LOOP
********************/
void SnakeEngine::run() {
    using namespace snakedisplay;

    isRunning = true;

    fruit.generateAtRandomPosition(snake, area);
    
    basicdisplay::clearScreen();
    drawSnake(snake);
    drawFruit(fruit);
    drawRightBoundary();
    drawScoreTitle();
    drawScore(score);

    while (isRunning) {

        if (frameTimer.isExpired()) {

            if (userInput->isPressedJoysticDown()) {
                snake.changeDirection(Direction::Down);
            } else if (userInput->isPressedJoysticUp()) {
                snake.changeDirection(Direction::Up);
            } else if (userInput->isPressedJoysticLeft()) {
                snake.changeDirection(Direction::Left);
            } else if (userInput->isPressedJoysticRight()) {
                snake.changeDirection(Direction::Right);
            } else if (userInput->isPressedRightButton()) {
                isRunning = false;
            }

            snake.move();

            if (snake.isCollidingWithItself() || area.isOutOfBound(snake.getHeadPosition())) {
                isRunning = false;
            }

            bool fruitEaten = false;

            if (snake.getHeadPosition() == fruit.getPosition()) {
                fruitEaten = true;
                snake.grow();

                bool generatedNewFruit = fruit.generateAtRandomPosition(snake, area);

                if (!generatedNewFruit) {
                    isRunning = false;
                    continue;
                }

                score.incrementScore();
                drawScore(score);
            }

            frameTimer.reset();

            updateSnake(snake);

            if (fruitEaten) {
                drawFruit(fruit);
            }
        }
    }

    basicdisplay::clearScreen();
    drawGameOver(score);

    std::chrono::milliseconds duration(3000);
    std::this_thread::sleep_for(duration);
}

}