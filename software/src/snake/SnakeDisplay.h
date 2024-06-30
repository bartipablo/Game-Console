#ifndef SnakeDisplay_H
#define SnakeDisplay_H

#include "../utils/DigitalLCD.h"
#include "Snake.h"
#include "Fruit.h"
#include "Area.h"
#include "Score.h"

namespace snake {

/**
 * Represents the display of the snake game.
 */
class SnakeDisplay {

public:
/**
 * Draw a whole snake
 */
    void drawSnake(Snake* snake);

/**
 * Draw a snake's head and remove the previous tail
 */
    void updateSnake(Snake* snake);

    void drawFruit(Fruit* fruit);

    void drawRightBoundary();

    void drawScoreTitle();

    void drawScore(Score* score);

    void drawGameOver(Score* score);

private:
    Arduino_ILI9341* display = DigitalLCD::getInstance();
};

}


#endif