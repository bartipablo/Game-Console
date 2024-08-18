#ifndef SCORE_H
#define SCORE_H

#include "Serializable.h"

namespace pong {

/**
 * The Score class represents the score of a player in the Pong game.
 */
class Score : public streams::Serializable {

public:
    Score();

    void giveScore() {
        score++;
    }

    int getScore() const {
        return score;
    }

    void reset() {
        score = 0;
    }

    void write(streams::OutputMemoryStream &stream);

    void read(streams::InputMemoryStream &stream);

private:
    int8_t score;
};


}

#endif