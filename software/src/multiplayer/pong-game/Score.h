#ifndef SCORE_H
#define SCORE_H

#include "../streams/Serializable.h"

namespace pong {

/**
 * The Score class represents the score of a player in the Pong game.
 */
class Score : public Serializable {

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

    void write(OutputMemoryStream &stream);

    void read(InputMemoryStream &stream);

private:
    int8_t score;
};


}

#endif