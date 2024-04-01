#ifndef Tetromino_H
#define Tetromino_H

#include "Block.h"
#include "Vector2D.h"
#include "Direction.h"
#include "TetrisProperties.h"
#include "PlayingField.h"
#include <vector>

class Tetromino {
public:
    Tetromino(PlayingField& field) : playingField(field), direction(Direction::Up) {}

    virtual void rotateClockwise(const PlayingField& playingField) = 0;

    virtual void rotateAntiClockwise(const PlayingField& playingField) = 0;

    std::vector<Block> getBlocks();

    std::vector<Vector2D> getPositions();

    void move(int x, int y, const PlayingField& playingField);


protected:
    static constexpr int MAX_BLOCKS = 4;

    Block blocks[MAX_BLOCKS];

    PlayingField playingField;

    Direction direction;

    void rotateForSpecyficTetrominos(int xRotate[4][4], int yRotate[4][4], const PlayingField& playingField, Direction (*newDirection)(Direction));
};

#endif
