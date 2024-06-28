#include "Area.h"

namespace snake {

bool Area::isOutOfBound(Vector2D position) const {
    return position.x() < 0 || position.x() >= WIDTH || position.y() < 0 || position.y() >= HEIGHT;
}

}