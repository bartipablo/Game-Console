#ifndef PADDLE_H
#define PADDLE_H

#include "../streams/Serializable.h"
#include "Table.h"

namespace pong {

/**
 * The paddle class represents a player paddle in the Pong game.
 */
class Paddle : public Serializable {
public:
    Paddle(int x, int y);

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

/**
 * Move the paddle up or down.
 * @param y The amount to move the paddle.
*/
    void move(int y);

    void write(OutputMemoryStream &stream);

    void read(InputMemoryStream &stream);

/**
 * Reset the paddle to the initial position.
 */
    void reset();

    static int const HEIGHT = 30;

    static int const WIDTH = 6;

private:
    int16_t x;
    const int16_t initX;

    int16_t y;
    const int16_t initY;
};

}

#endif