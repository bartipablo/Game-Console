#ifndef TetrominoL2_H
#define TetrominoL2_H

#include "Tetromino.h"

class TetrominoL2 : public Tetromino {
public:
    TetrominoL2(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField),
          xRotate({{0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}}),
          yRotate({{2, 1, 0, -1}, {0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}}),

          xAntiRotate({{-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}, {0, -1, 0, 1}}),
          yAntiRotate({{0, -1, 0, 1}, {-2, -1, 0, 1}, {0, 1, 0, -1}, {2, 1, 0, -1}}) {

        blocks[0] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
        blocks[1] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[3] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
    }

    virtual void rotateClockwise(const PlayingField& playingField) override {
       rotateForSpecyficTetrominos(xRotate, yRotate, playingField);
       direction = nextDirection(direction);
    }

    virtual void rotateAntiClockwise(const PlayingField& playingField) override {
       rotateForSpecyficTetrominos(xAntiRotate, yAntiRotate, playingField);
       direction = previousDirection(direction);

    }

private:
    int xRotate[4][4];
    int yRotate[4][4];
    int xAntiRotate[4][4];
    int yAntiRotate[4][4];
};

#endif
