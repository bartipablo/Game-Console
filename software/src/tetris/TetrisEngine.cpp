#include "TetrisEngine.h"


TetrisEngine::TetrisEngine() : 
        playingField(), 
        tetrominoFactory(), 
        tetrisDisplay(), 
        userInput(UserInput::getInstance()), 
        loopCounter(0), 
        pause(false), 
        shutdown(false), 
        gameover(false),
        result(),
        inputBlocking() {}

void TetrisEngine::run() {

    Tetromino* actualTetromino = nullptr;
    Tetromino* nextTetromino = tetrominoFactory.getRandomTetromino();

    tetrisDisplay.drawFieldsDescription();
    tetrisDisplay.drawScore(result.getScore());
    tetrisDisplay.drawLevel(result.getLevel());
    tetrisDisplay.drawPlayingField(playingField);

    inputBlocking.startBlocking(40);

    while (!gameover) {

        actualTetromino = nextTetromino;
        nextTetromino = tetrominoFactory.getRandomTetromino();

        tetrisDisplay.clearNext();
        tetrisDisplay.drawNext(nextTetromino->getBlocks());

        if (isGameOver(actualTetromino->getPositions())) {
            gameover = true;
        }

        // draw next block, statistics etc.
       
       if (!gameover) {
            tetrisDisplay.drawBlocks(actualTetromino->getBlocks());
       }

        while (!gameover) {
            delay(17);

            // User controls.

            if (!inputBlocking.isBlocked()) {
                if (userInput->isPressedJoysticLeft()) {
                    moveTetromino(actualTetromino, -1, 0);
                }
                if (userInput->isPressedJoysticRight()) {
                    moveTetromino(actualTetromino, 1, 0);
                }
                if (userInput->isPressedJoysticDown()) {
                    moveTetromino(actualTetromino, 0, 1);
                }
                if (userInput->isPressedLeftButton()) {
                    rotateClockwiseTetromino(actualTetromino);
                }
                if (userInput->isPressedRightButton()) {
                    rotateAntiClockwiseTetromino(actualTetromino);
                }
                if (userInput->isPressedLeftButton()
                    && userInput->isPressedRightButton()
                    && userInput->isPressedJoysticButton()) {
                        gameover = true;
                }

            } else {
                inputBlocking.decrement();
            }

            if (shouldAutoMoveDown()) {
                moveTetromino(actualTetromino, 0, 1);
                loopCounter = 0;
            }


            if (isTetrominoPlaced(actualTetromino->getPositions())) {
                playingField.insertBlocks(actualTetromino->getBlocks());
                std::vector<int> linesToClear = findLinesToClear();

                if (!linesToClear.empty()) {
                    playingField.clearLines(linesToClear);
                    playingField.dropFloatingBlocks();
                    tetrisDisplay.drawPlayingField(playingField);
                    result.increase(linesToClear.size());
                    tetrisDisplay.clearScore();
                    tetrisDisplay.clearLevel();
                    tetrisDisplay.drawScore(result.getScore());
                    tetrisDisplay.drawLevel(result.getLevel());
                }

                tetrisDisplay.drawPlayingField(playingField);
                break;
            }

            loopCounter += 1;
        }

        delete actualTetromino;
    }
    delete nextTetromino;

    tetrisDisplay.displayGameOver(result.getScore(), result.getLevel());
    delay(1500);
    while (true) {
        delay(100);
         if (userInput->isPressedLeftButton() || userInput->isPressedRightButton()) {
            return;
         }
    }
}

bool TetrisEngine::isTetrominoPlaced(std::vector<Vector2D> positions) {
    if (!playingField.isEmptyPositionsBelow(positions)) {
        return true;
    } 
     
    for (const auto &position : positions) {
        if (position.y() >= 19) {
            return true;
        }
    }
    return false; 
}

bool TetrisEngine::isGameOver(std::vector<Vector2D> positions) {
    return !playingField.isEmptyPositions(positions);
}

std::vector<int> TetrisEngine::findLinesToClear() {
    std::vector<int> linesToClear;

    for (int i = 19; i >= 0; i--) {

        bool shouldClearLine = true;

        for (int j = 0; j < 10; j++) {
            if (playingField.isEmpty(Vector2D(j, i))) {
                shouldClearLine = false;
                break;
            }
        }
        
        if (shouldClearLine) {
            linesToClear.push_back(i);
        }
    }
    return linesToClear;
}


bool TetrisEngine::shouldAutoMoveDown() {
    int speed = result.getSpeed();
    if (loopCounter >= speed) {
        loopCounter = 0;
        return true;
    }
    return false;
}

void TetrisEngine::moveTetromino(Tetromino* tetromino, int x, int y) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->move(x, y, playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks());
    inputBlocking.startBlocking(10);
}

void TetrisEngine::rotateClockwiseTetromino(Tetromino* tetromino) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->rotateClockwise(playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks()); 
    inputBlocking.startBlocking(10);   
}

void TetrisEngine::rotateAntiClockwiseTetromino(Tetromino* tetromino) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->rotateAntiClockwise(playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks());
    inputBlocking.startBlocking(10);    
}