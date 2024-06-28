#ifndef Score_H
#define Score_H


namespace snake {

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