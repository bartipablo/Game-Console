#ifndef SnakeFruit_H
#define SnakeFruit_H

#include "../common/Vector2D.h"
#include "Snake.h"
#include "Area.h"

namespace snake {

/**
 * Represents a fruit that the snake can eat.
 */
class Fruit {

public:
    Fruit(Vector2D position) : position(position) {}

    Vector2D getPosition();

    /**
     * Generates a new fruit at a random position that is not occupied by the snake.
     * If it is not possible to generate the fruit (because there is no free position), it returns false.
     * @return true if the fruit was generated, false otherwise.
     */
    bool generateAtRandomPosition(Snake* snake, Area* area);

    const static int SIZE = 6;

private:
    Vector2D position;    
};

}

#endif