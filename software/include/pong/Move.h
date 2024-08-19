#ifndef MOVE_H
#define MOVE_H

#include "Serializable.h"

namespace pong {

/**
 * The Move class represents a player paddle move in the Pong game.
 */
class Move : public streams::Serializable {
public:
    Move() : y(0) {}

    Move(int y) : y(y) {}

    int getY() const {
        return y;
    }

    void write(streams::OutputMemoryStream &stream) override;

    void read(streams::InputMemoryStream &stream) override;

private:
    int8_t y;
};

}

#endif