#include "Engine.h"

Engine::Engine() : 
        playingField(), 
        tetrominoFactory(playingField), 
        tetrisDisplay(), 
        userInput(UserInput::getInstance()), 
        loopCounter(0), 
        pause(false), 
        shutdown(false), 
        gameover(false),
        result() {}

void Engine::run() {

    Tetromino* actualTetromino = nullptr;
    Tetromino* nextTetromino = tetrominoFactory.getRandomTetromino();

    tetrisDisplay.displayPlayingField(playingField);

    while (!gameover) {

        actualTetromino = nextTetromino;
        nextTetromino = tetrominoFactory.getRandomTetromino();

        if (isGameOver(actualTetromino->getPositions())) {
            gameover = true;
        }

        // draw next block, statistics etc.
       
       if (!gameover) {
            tetrisDisplay.drawBlocks(actualTetromino->getBlocks());
       }

        while (!gameover) {
            delay(150);

            // User controls.
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

            if (shouldAutoMoveDown()) {
                moveTetromino(actualTetromino, 0, 1);
                loopCounter = 0;
            }


            if (isTetrominoPlaced(actualTetromino->getPositions())) {
                playingField.insertBlocks(actualTetromino->getBlocks());
                std::vector<int> linesToClear = findLinesToClear();

                if (!linesToClear.empty()) {
                    //display special effects about clearing lines.
                    playingField.clearLines(linesToClear);
                    playingField.dropFloatingBlocks();
                    tetrisDisplay.displayPlayingField(playingField);
                    result.increase(linesToClear.size());
                }

                tetrisDisplay.displayPlayingField(playingField);
                break;
            }

            loopCounter += 1;
        }

        delete actualTetromino;
    }
    delete nextTetromino;
}

bool Engine::isTetrominoPlaced(std::vector<Vector2D> positions) {
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

bool Engine::isGameOver(std::vector<Vector2D> positions) {
    return !playingField.isEmptyPositions(positions);
}

std::vector<int> Engine::findLinesToClear() {
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


bool Engine::shouldAutoMoveDown() {
    int speed = result.getSpeed();
    if (loopCounter >= speed) {
        loopCounter = 0;
        return true;
    }
    return false;
}

void Engine::moveTetromino(Tetromino* tetromino, int x, int y) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->move(x, y, playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks());
}

void Engine::rotateClockwiseTetromino(Tetromino* tetromino) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->rotateClockwise(playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks());    
}

void Engine::rotateAntiClockwiseTetromino(Tetromino* tetromino) {
    tetrisDisplay.clearAtPositions(tetromino->getPositions());
    tetromino->rotateAntiClockwise(playingField);
    tetrisDisplay.drawBlocks(tetromino->getBlocks());    
}