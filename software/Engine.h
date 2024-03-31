#ifndef Engine_H
#define Engine_H

#include <vector>

#include "Result.h"
#include "PlayingField.h"
#include "Tetromino.h"
#include "TetrominoFactory.h"
#include "TetrisDisplay.h"
#include "Arduino.h"
#include "./src/UserInput.h"

class Engine {

public:
    Engine();

    void run();

private:
    
    bool isTetrominoPlaced(std::vector<Vector2D> positions);

    bool isGameOver(std::vector<Vector2D> positions);

    bool shouldAutoMoveDown();

    std::vector<int> findLinesToClear();

    void moveTetromino(Tetromino* tetromino, int x, int y);

    void rotateClockwiseTetromino(Tetromino* tetromino);

    void rotateAntiClockwiseTetromino(Tetromino* tetromino);

    Result result;

    PlayingField playingField;

    TetrominoFactory tetrominoFactory;

    TetrisDisplay tetrisDisplay;

    UserInput* userInput;

    int loopCounter;

    bool gameover;

    bool pause;

    bool shutdown;
};


#endif
