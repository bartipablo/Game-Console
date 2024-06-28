#ifndef SnakeDisplay_H
#define SnakeDisplay_H

#include "../utils/DigitalLCD.h"
#include "Snake.h"
#include "Fruit.h"
#include "Area.h"
#include "Score.h"

namespace snake {

class SnakeDisplay {

public:
    void drawSnake(Snake* snake);

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