#ifndef Result_H
#define Result_H


/**
 * @brief Class representing the result in Tetris.
 * 
 * The Result class manages the player's score, level, and speed in Tetris.
 * It provides methods to increase the score based on the number of cleared lines,
 * retrieve the current score, level, and speed.
 */
class Result {

public:
    Result();

    /**
     * @brief Increases the score and updates other parameters based on the number of clearing lines.
     * 
     * @param clearingLines The number of lines cleared in the last move.
     */
    void increase(int clearingLines);

    int getScore();

    int getLevel();

    int getSpeed();

private:
    int score;
    int clearingLinesNo;
    int level;
    int speed;

    /**
     * @brief Updates the score based on the number of clearing lines.
     * 
     * @param clearingLines The number of lines cleared in the last move.
     */
    void updateScore(int clearingLines);

    /**
     * @brief Updates the total number of clearing lines.
     * 
     * @param clearingLines The number of lines cleared in the last move.
     */
    void updateClearingLinesNo(int clearingLines);

    /**
     * @brief Updates the level based on the total number of clearing lines.
     */
    void updateLevel();

    /**
     * @brief Updates the speed based on the current level.
     */
    void updateSpeed();
};


#endif
