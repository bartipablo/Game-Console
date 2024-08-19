#ifndef SnakeScore_H
#define SnakeScore_H

namespace snake {

/**
 * Represents the score of the player.
 */
class Score {

public:
    void incrementScore() {
        score++;
    }

    int getScore() const {
        return score;
    }

private:
    int score = 0;
};

}

#endif