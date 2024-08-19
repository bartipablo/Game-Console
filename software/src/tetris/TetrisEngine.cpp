#include "TetrisEngine.h"

namespace tetris {

TetrisEngine::TetrisEngine() : 
        loopCounter{0}, 
        pause(false), 
        shutdown(false), 
        gameover(false) {}

void TetrisEngine::run() {
    using namespace tetrisdisplay;

    Tetromino actualTetromino = tetrominoFactory.getRandomTetromino();
    Tetromino nextTetromino = tetrominoFactory.getRandomTetromino();

    drawFieldsDescription();
    drawScore(result.getScore());
    drawLevel(result.getLevel());
    drawPlayingField(playingField);

    inputBlocking.startBlocking(40);

    while (!gameover) {

        actualTetromino = nextTetromino;
        nextTetromino = tetrominoFactory.getRandomTetromino();

        clearNext();
        drawNext(nextTetromino.getBlocks());

        if (isGameOver(actualTetromino.getPositions())) {
            gameover = true;
        }

        // draw next block, statistics etc.
       
       if (!gameover) {
            drawBlocks(actualTetromino.getBlocks());
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


            if (isTetrominoPlaced(actualTetromino.getPositions())) {
                playingField.insertBlocks(actualTetromino.getBlocks());
                std::vector<int> linesToClear = findLinesToClear();

                if (!linesToClear.empty()) {
                    playingField.clearLines(linesToClear);
                    playingField.dropFloatingBlocks();
                    drawPlayingField(playingField);
                    result.increase(linesToClear.size());
                    clearScore();
                    clearLevel();
                    drawScore(result.getScore());
                    drawLevel(result.getLevel());
                }

                drawPlayingField(playingField);
                break;
            }

            loopCounter += 1;
        }
    }

    displayGameOver(result.getScore(), result.getLevel());
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


void TetrisEngine::moveTetromino(Tetromino& tetromino, int x, int y) {
    using namespace tetrisdisplay;

    clearAtPositions(tetromino.getPositions());
    tetromino.move(x, y, playingField);
    drawBlocks(tetromino.getBlocks());
    inputBlocking.startBlocking(10);
}


void TetrisEngine::rotateClockwiseTetromino(Tetromino& tetromino) {
    using namespace tetrisdisplay;

    clearAtPositions(tetromino.getPositions());
    tetromino.rotateClockwise(playingField);
    drawBlocks(tetromino.getBlocks()); 
    inputBlocking.startBlocking(10);   
}


void TetrisEngine::rotateAntiClockwiseTetromino(Tetromino& tetromino) {
    using namespace tetrisdisplay;

    clearAtPositions(tetromino.getPositions());
    tetromino.rotateAntiClockwise(playingField);
    drawBlocks(tetromino.getBlocks());
    inputBlocking.startBlocking(10);    
}

}