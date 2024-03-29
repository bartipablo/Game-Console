#ifndef TetrominoSkew1_H
#define TetrominoSkew1_H

#include "Tetromino.h"

class TetrominoSkew1 : public Tetromino
{
public:
    TetrominoSkew1(Vector2D initialPosition, PlayingField& playingField, int color)
        : Tetromino(playingField) {

        blocks[0] = Block(color, Vector2D(initialPosition.x() - 1, initialPosition.y() + 1));
        blocks[1] = Block(color, Vector2D(initialPosition.x(), initialPosition.y() + 1));
        blocks[2] = Block(color, Vector2D(initialPosition.x(), initialPosition.y()));
        blocks[3] = Block(color, Vector2D(initialPosition.x() + 1, initialPosition.y()));
    }

    virtual void rotateClockwise() override {
        Vector2D prevPositions[MAX_BLOCKS];

        for (int i = 0; i < MAX_BLOCKS; ++i) {
            prevPositions[i] = blocks[i].getPosition();
        }

        Vector2D newPositions[MAX_BLOCKS];

        switch (direction) {
            case Direction::Up:
                newPositions[0] = Vector2D(prevPositions[0].x() + 1, prevPositions[0].y() - 1);
                newPositions[1] = Vector2D(prevPositions[1].x(), prevPositions[1].y());
                newPositions[2] = Vector2D(prevPositions[2].x() + 1, prevPositions[2].y() + 1);
                newPositions[3] = Vector2D(prevPositions[3].x(), prevPositions[3].y() + 2);
                break;
            case Direction::Right:
                newPositions[0] = Vector2D(prevPositions[0].x() + 1, prevPositions[0].y() + 1);
                newPositions[1] = Vector2D(prevPositions[1].x(), prevPositions[1].y());
                newPositions[2] = Vector2D(prevPositions[2].x() - 1, prevPositions[2].y() + 1);
                newPositions[3] = Vector2D(prevPositions[3].x() - 2, prevPositions[3].y());
                break;
            case Direction::Down:
                newPositions[0] = Vector2D(prevPositions[0].x() - 1, prevPositions[0].y() + 1);
                newPositions[1] = Vector2D(prevPositions[1].x(), prevPositions[1].y());
                newPositions[2] = Vector2D(prevPositions[2].x() - 1, prevPositions[2].y() - 1);
                newPositions[3] = Vector2D(prevPositions[3].x(), prevPositions[3].y() - 2);
                break;
            case Direction::Left:
                newPositions[0] = Vector2D(prevPositions[0].x() - 1, prevPositions[0].y() - 1);
                newPositions[1] = Vector2D(prevPositions[1].x(), prevPositions[1].y());
                newPositions[2] = Vector2D(prevPositions[2].x() + 1, prevPositions[2].y() - 1);
                newPositions[3] = Vector2D(prevPositions[3].x() + 2, prevPositions[3].y());
                break;
        }

        for (int i = 0; i < MAX_BLOCKS; i++) {
            if (newPositions[i].x() < TetrisProperties::minX || newPositions[i].x() > TetrisProperties::maxX 
            || newPositions[i].y() < TetrisProperties::minY || newPositions[i].y() > TetrisProperties::maxY || !playingField.isEmpty(newPositions[i])) {
                return;
            } 
        }
        direction = nextDirection(direction);

        for (int i = 0; i < MAX_BLOCKS; i++) {
            blocks[i].updatePosition(newPositions[i]);
        }
    }

};

#endif
