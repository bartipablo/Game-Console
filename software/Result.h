#ifndef Result_H
#define Result_H

class Result {

public:
    Result();

    void increase(int clearingLines);

    int getScore();

    int getLevel();

    int getSpeed();

private:
    int score;

    int clearingLinesNo;

    int level;

    int speed;

    void updateScore(int clearingLines);

    void updateClearingLinesNo(int clearingLines);

    void updateLevel();

    void updateSpeed();
};


#endif
