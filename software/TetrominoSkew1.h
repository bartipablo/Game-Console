#ifndef TetrominoSkew1_H
#define TetrominoSkew1_H

#include "Tetromino.h"

class TetrominoSkew1 : public Tetromino
{
public:
    TetrominoSkew1(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField),
          xRotate({{1, 0, 1, 0}, {1, 0, -1, -2}, {-1, 0, -1, 0}, {-1, 0, 1, 2}}),
          yRotate({{-1, 0, 1, 2}, {1, 0, 1, 0}, {1, 0, -1, -2}, {-1, 0, -1, 0}}) {

        blocks[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
        blocks[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
    }

    virtual void rotateClockwise() override {
        rotateForSpecyficTetrominos(xRotate, yRotate);
    }

private:
    int xRotate[4][4];
    
    int yRotate[4][4];

};

#endif
