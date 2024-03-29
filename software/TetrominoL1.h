#ifndef TetrominoL1_H
#define TetrominoL1_H

#include "Tetromino.h"

class TetrominoL1 : public Tetromino
{
public:
    TetrominoL1(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField),
          xRotate({{2, 1, 0, -1}, {0, 1, 0, -1}, {-2, -1, 0, 1}, {0, -1, 0, 1}}),
          yRotate({{0, -1, 0, 1}, {2, 1, 0, -1}, {0, 1, 0, -1}, {-2, -1, 0, 1}}) {

        blocks[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y()));
        blocks[1] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));
    }

    virtual void rotateClockwise() override {
        rotateForSpecyficTetrominos(xRotate, yRotate);
    }

private:
    int xRotate[4][4];
    
    int yRotate[4][4];
};

#endif