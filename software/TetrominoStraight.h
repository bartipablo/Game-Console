#ifndef TetrominoStraight_H
#define TetrominoStraight_H

#include "Tetromino.h"

class TetrominoStraight : public Tetromino
{
public:
    TetrominoStraight(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField),
          xRotate({{2, 1, 0, -1}, {1, 0, -1, -2}, {-2, -1, 0, 1}, {-1, 0, 1, 2}}),
          yRotate({{-1, 0, 1, 2}, {2, 1, 0, -1}, {1, 0, -1, -2}, {-2,-1, 0, 1}}) {

        blocks[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y()));
        blocks[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
        blocks[2] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 2, initialPosition.y()));
    }

    virtual void rotateClockwise() override {
        rotateForSpecyficTetrominos(xRotate, yRotate);
    }

private:
    int xRotate[4][4];
    
    int yRotate[4][4];

};
#endif
