#ifndef Direction_H
#define Direction_H

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

Direction nextDirection(Direction currentDirection);

Direction previousDirection(Direction currentDirection);

#endif
