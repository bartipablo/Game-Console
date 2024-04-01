#ifndef TetrominoT_H
#define TetrominoT_H

#include "Tetromino.h"

class TetrominoT : public Tetromino {
public:
    TetrominoT(Vector2D initialPosition, int color)
        :
          xRotate({{1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}}),
          yRotate({{1, -1, 0, 1}, {1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}}),

          xAntiRotate({{-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}, {1, 1, 0, -1}}),
          yAntiRotate({{1, 1, 0, -1}, {-1, 1, 0, -1}, {-1, -1, 0, 1}, {1, -1, 0, 1}}) {

        blocks[0] = Block(color, initialPosition);
        blocks[1] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));
    }


    virtual void rotateClockwise(const PlayingField& playingField) override {
        rotateForSpecyficTetrominos(xRotate, yRotate, playingField, nextDirection);

    }

    virtual void rotateAntiClockwise(const PlayingField& playingField) override {
        rotateForSpecyficTetrominos(xAntiRotate, yAntiRotate, playingField, previousDirection);
    }

private:
    int xRotate[4][4];
    int yRotate[4][4];
    int xAntiRotate[4][4];
    int yAntiRotate[4][4];
};

#endif
