#ifndef TetrominoSquare_H
#define TetrominoSquare_H

#include "Tetromino.h"

class TetrominoSquare : public Tetromino
{
public:
    TetrominoSquare(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField) {

        blocks[0] = Block(color, initialPosition);
        blocks[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));
    }

    virtual void rotateClockwise() override {
        return;
    }

};

#endif