#ifndef TetrominoT_H
#define TetrominoT_H

#include "Tetromino.h"

class TetrominoT : public Tetromino
{
public:
    TetrominoT(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField),
          xRotate({{1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}}),
          yRotate({{1, -1, 0, 1}, {1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}}) {

        blocks[0] = Block(color, initialPosition);
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