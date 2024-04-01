#ifndef Engine_H
#define Engine_H

#include <vector>

#include "Result.h"
#include "PlayingField.h"
#include "Tetromino.h"
#include "TetrominoFactory.h"
#include "TetrisDisplay.h"
#include "InputBlocking.h"
#include "Arduino.h"
#include "./src/UserInput.h"


/**
 * @brief Class representing the core engine of the Tetris game.
 * 
 * The TetrisEngine class manages the game loop, user input, Tetromino generation,
 * and gameplay mechanics for the Tetris game.
 */
class TetrisEngine {

public:
    /**
     * @brief Constructor for the TetrisEngine class.
     * 
     * Initializes various components required for the game.
     */
    TetrisEngine();

    /**
     * @brief Method to start and run the Tetris game.
     * 
     * The run() method executes the main game loop, handling Tetromino generation,
     * user input, Tetromino movement, line clearing, and game over conditions.
     */
    void run();

private:
    InputBlocking inputBlocking;
    Result result;
    PlayingField playingField;
    TetrominoFactory tetrominoFactory;
    TetrisDisplay tetrisDisplay;
    UserInput* userInput;
    int loopCounter;
    bool gameover;
    bool pause;
    bool shutdown;
    
    bool isTetrominoPlaced(std::vector<Vector2D> positions);

    bool isGameOver(std::vector<Vector2D> positions);

    bool shouldAutoMoveDown();

    std::vector<int> findLinesToClear();

    void moveTetromino(Tetromino* tetromino, int x, int y);

    void rotateClockwiseTetromino(Tetromino* tetromino);

    void rotateAntiClockwiseTetromino(Tetromino* tetromino);    
};


#endif
