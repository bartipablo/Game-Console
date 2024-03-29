#ifndef StraightTetromino_H
#define StraightTetromino_H

#include "Tetromino.h"

class StraightTetromino : public Tetromino
{
public:
    StraightTetromino(Vector2D initialPosition, PlayingField& playingField)
        : Tetromino(playingField) {

        for (int i = 0; i < 4; ++i) {
            Vector2D blockPosition = Vector2D(initialPosition.x() + i, initialPosition.y());
            Block newBlock(2, blockPosition);
            blocks[i] = newBlock;
        }
    }

    virtual void rotateClockwise() override {
        Vector2D prevPositions[4];

        for (int i = 0; i < 4; ++i) {
            prevPositions[i] = blocks[i].getPosition();
        }

        Vector2D newPositions[4];

        switch (direction) {
            case Direction::Up:
                newPositions[0] = Vector2D(prevPositions[0].x() + 2, prevPositions[0].y() + 1);
                newPositions[1] = Vector2D(prevPositions[1].x() + 1, prevPositions[1].y());
                newPositions[2] = Vector2D(prevPositions[2].x(), prevPositions[2].y() - 1);
                newPositions[3] = Vector2D(prevPositions[3].x() - 1, prevPositions[3].y() - 2);
                break;
            case Direction::Right:
                newPositions[0] = Vector2D(prevPositions[0].x() + 1, prevPositions[0].y() + 2);
                newPositions[1] = Vector2D(prevPositions[1].x(), prevPositions[1].y() - 1);
                newPositions[2] = Vector2D(prevPositions[2].x() - 1, prevPositions[2].y());
                newPositions[3] = Vector2D(prevPositions[3].x() - 2, prevPositions[3].y() + 1);
                break;
            case Direction::Down:
                newPositions[0] = Vector2D(prevPositions[0].x() + 2, prevPositions[0].y() + 1);
                newPositions[1] = Vector2D(prevPositions[1].x() + 1, prevPositions[1].y() + 1);
                newPositions[2] = Vector2D(prevPositions[2].x() - 1, prevPositions[2].y());
                newPositions[3] = Vector2D(prevPositions[3].x() - 1, prevPositions[3].y() - 1);
                break;
            case Direction::Left:
                newPositions[0] = Vector2D(prevPositions[0].x() + 2, prevPositions[0].y() + 1);
                newPositions[1] = Vector2D(prevPositions[1].x() + 1, prevPositions[1].y() - 1);
                newPositions[2] = Vector2D(prevPositions[2].x(), prevPositions[2].y() + 1);
                newPositions[3] = Vector2D(prevPositions[3].x() - 1, prevPositions[3].y() + 2);
                break;
        }

        for (int i = 0; i < MAX_BLOCKS; i++) {
            if (!playingField.isEmpty(newPositions[i])) return;
        }

        for (int i = 0; i < MAX_BLOCKS; i++) {
            blocks[i].updatePosition(newPositions[i]);
        }
    }

};

#endif
