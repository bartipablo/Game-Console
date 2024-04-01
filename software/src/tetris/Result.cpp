#include "Result.h"


Result::Result() {
    this->score = 0;
    this->clearingLinesNo = 0;
    this->level = 0;
    this->speed = 48;
}

void Result::increase(int clearingLines) {
    updateScore(clearingLines);
    updateClearingLinesNo(clearingLines);
    updateLevel();
    updateSpeed();
}

int Result::getLevel() {
    return level;
}

int Result::getScore() {
    return score;
}

int Result::getSpeed() {
    return speed;
}

void Result::updateScore(int clearingLines) {
    switch(clearingLines) {
        case 1:
            score += 40 * (level + 1);
            break;
        case 2:
            score += 100 * (level + 1);
            break;
        case 3:
            score += 300 * (level + 1);
            break;
        case 4:
            score += 1200 * (level + 1);
            break;
    }
}

void Result::updateClearingLinesNo(int clearingLines) {
    clearingLinesNo += clearingLines;
}

void Result::updateLevel() {
    if (clearingLinesNo == 0) return;

    if (clearingLinesNo >= (level + 1) * 10) {
        level++;
    }
} 

void Result::updateSpeed() {
    if (level <= 8) {
        speed = 48 - level * 5;
    } else if (level == 9) {
        speed = 6;
    } else if (level >= 10 && level <= 12) {
        speed = 5;
    } else if (level >= 13 && level <= 15) {
        speed = 4;
    } else if (level >= 16 && level <= 18) {
        speed = 3;
    } else if (level >= 19 && level <= 28) {        
        speed = 2;
    } else {
        speed = 1;
    }
};