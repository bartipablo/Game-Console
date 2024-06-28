#ifndef SnakeFruit_H
#define SnakeFruit_H

#include "../common/Vector2D.h"
#include "Snake.h"
#include "Area.h"

namespace snake {

class Fruit {

public:
    Fruit(Vector2D position) : position(position) {}

    Vector2D getPosition();

    void generateAtRandomPosition(Snake* snake, Area* area);

private:
    Vector2D position;    
};

}

#endif