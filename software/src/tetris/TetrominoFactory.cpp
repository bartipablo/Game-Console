#include "TetrominoFactory.h"

namespace tetris {

TetrominoFactory::TetrominoFactory() {
        randomSeed(analogRead(23));
    }

Tetromino TetrominoFactory::getRandomTetromino() {
    int color = getRandomColor();
    int randomNumber = getRandomNumber(8);

    switch (randomNumber) {
        case 1: {
            return createL1Tetromino(Vector2D(4, 0), color);
        }
        case 2: {
            return createL2Tetromino(Vector2D(5, 0), color);
        }
        case 3: {
            return createTTetromino(Vector2D(4, 0), color);
        }   
        case 4: {
            return createSkew1Tetromino(Vector2D(4, 0), color);
        }
        case 5: {
            return createSkew2Tetromino(Vector2D(5, 0), color);
        }
        case 6: {
            return createStraightTetromino(Vector2D(4, 0), color);
        }
        default: {
            return createSquareTetromino(Vector2D(4, 0), color);
        }
    }
}


int TetrominoFactory::getRandomColor() {
    int randomNumber = getRandomNumber(4);
    switch(randomNumber) {
        case 1:
            return Color::BLUE_;
        case 2:
            return Color::GREEN_;
        case 3:
            return Color::RED_;
        default:
            return Color::YELLOW_;
    }
}


int TetrominoFactory::getRandomNumber(int range) {
    return random(1, range);
}


Tetromino TetrominoFactory::createL1Tetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{2, 1, 0, -1}, {0, 1, 0, -1}, {-2, -1, 0, 1}, {0, -1, 0, 1}};
    int yRotateInit[4][4] = {{0, -1, 0, 1}, {2, 1, 0, -1}, {0, 1, 0, -1}, {-2, -1, 0, 1}};
    int xAntiRotateInit[4][4] = {{0, 1, 0, -1}, {-2, -1, 0, 1}, {0, -1, 0, 1}, {2, 1, 0, -1}};
    int yAntiRotateInit[4][4] = {{ 2, 1, 0, -1}, {0, 1, 0, -1}, {-2, -1, 0, 1}, {0, -1, 0, 1}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y()));
    blocksInit[1] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createL2Tetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}};
    int yRotateInit[4][4] = {{2, 1, 0, -1}, {0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}};
    int xAntiRotateInit[4][4] = {{-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}, {0, -1, 0, 1}};
    int yAntiRotateInit[4][4] = {{0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
    blocksInit[1] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createSkew1Tetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{1, 0, 1, 0}, {1, 0, -1, -2}, {-1, 0, -1, 0}, {-1, 0, 1, 2}};
    int yRotateInit[4][4] = {{-1, 0, 1, 2}, {1, 0, 1, 0}, {1, 0, -1, -2}, {-1, 0, -1, 0}};
    int xAntiRotateInit[4][4] = {{1, 0, -1, -2}, {-1, 0, -1, 0}, {-1, 0, 1, 2}, {1, 0, 1, 0}};
    int yAntiRotateInit[4][4] = {{1, 0, 1, 0}, {1, 0, -1, -2}, {-1, 0, -1, 0}, {-1, 0, 1, 2}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
    blocksInit[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createSkew2Tetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{2, 1, 0, -1}, {0, -1, 0, -1}, {-2, -1, 0, 1}, {0, 1, 0, 1}};
    int yRotateInit[4][4] = {{0, 1, 0, 1}, {2, 1, 0, -1}, {0, -1, 0, -1}, {-2, -1, 0, 1}};
    int xAntiRotateInit[4][4] = {{0, -1, 0, -1}, {-2, -1, 0, 1}, {0, 1, 0, 1}, {2, 1, 0, -1}};
    int yAntiRotateInit[4][4] = {{2, 1, 0, -1}, {0, -1, 0, -1}, {-2, -1, 0, 1}, {0, 1, 0, 1}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y()));
    blocksInit[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createSquareTetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int yRotateInit[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int xAntiRotateInit[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int yAntiRotateInit[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, initialPosition);
    blocksInit[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createStraightTetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{2, 1, 0, -1}, {1, 0, -1, -2}, {-2, -1, 0, 1}, {-1, 0, 1, 2}};
    int yRotateInit[4][4] = {{-1, 0, 1, 2}, {2, 1, 0, -1}, {1, 0, -1, -2}, {-2,-1, 0, 1}};
    int xAntiRotateInit[4][4] = {{1, 0, -1, -2}, {-2, -1, 0, 1}, {-1, 0, 1, 2}, {2, 1, 0, -1}}; 
    int yAntiRotateInit[4][4] = {{2, 1, 0, -1}, {1, 0, -1, -2}, {-2, -1, 0, 1}, {-1, 0, 1, 2}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y()));
    blocksInit[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 2, initialPosition.y()));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}


Tetromino TetrominoFactory::createTTetromino(Vector2D initialPosition, int color) {
    int xRotateInit[4][4] = {{1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}};
    int yRotateInit[4][4] = {{1, -1, 0, 1}, {1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}};
    int xAntiRotateInit[4][4] = {{-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}, {1, 1, 0, -1}};
    int yAntiRotateInit[4][4] = {{1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}};

    Block blocksInit[4];

    blocksInit[0] = Block(color, initialPosition);
    blocksInit[1] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
    blocksInit[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
    blocksInit[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));

    return Tetromino{xRotateInit, yRotateInit, xAntiRotateInit, yAntiRotateInit, blocksInit};
}

}