#include "Tetromino.h"

std::vector<Block> Tetromino::getBlocks() {
        return std::vector<Block>(blocks, blocks + MAX_BLOCKS);
}

std::vector<Vector2D> Tetromino::getPositions() {
    std::vector<Vector2D> positions;
    for (const auto &block : blocks) {
        positions.push_back(block.getPosition());
    }
    return positions;
}


void Tetromino::move(int x, int y, const PlayingField& playingField) {


    for (auto &block : blocks) {
        Vector2D actualPosition = block.getPosition();
        Vector2D newPosition = Vector2D(actualPosition.x() + x, actualPosition.y() + y);

        if (newPosition.x() < TetrisProperties::minX || newPosition.x() > TetrisProperties::maxX || newPosition.y() < TetrisProperties::minY || newPosition.y() > TetrisProperties::maxY || !playingField.isEmpty(newPosition)) {
            return;
        }
    }

    for (auto &block : blocks) {
        Vector2D actualPosition = block.getPosition();
        Vector2D newPosition = Vector2D(actualPosition.x() + x, actualPosition.y() + y);
        block.updatePosition(newPosition);
    }
}


void Tetromino:: rotateForSpecyficTetrominos(int xRotate[4][4], int yRotate[4][4], const PlayingField& playingField, Direction (*newDirection)(Direction)) {
        Vector2D prevPositions[MAX_BLOCKS];

        for (int i = 0; i < MAX_BLOCKS; ++i) {
            prevPositions[i] = blocks[i].getPosition();
        }

        Vector2D newPositions[MAX_BLOCKS];

        int rotationNo = 0;

        switch (direction) {
            case Direction::Up:
                rotationNo = 0;
                break;
            case Direction::Right:
                rotationNo = 1;
                break;
            case Direction::Down:
                rotationNo = 2;
                break;
            case Direction::Left:
                rotationNo = 3;
                break;
            default:
                rotationNo = 0;
        }

        newPositions[0] = Vector2D(prevPositions[0].x() + xRotate[rotationNo][0], prevPositions[0].y() + yRotate[rotationNo][0]);
        newPositions[1] = Vector2D(prevPositions[1].x() + xRotate[rotationNo][1], prevPositions[1].y() + yRotate[rotationNo][1]);
        newPositions[2] = Vector2D(prevPositions[2].x() + xRotate[rotationNo][2], prevPositions[2].y() + yRotate[rotationNo][2]);
        newPositions[3] = Vector2D(prevPositions[3].x() + xRotate[rotationNo][3], prevPositions[3].y() + yRotate[rotationNo][3]);

        for (int i = 0; i < MAX_BLOCKS; i++) {
            if (newPositions[i].x() < TetrisProperties::minX || newPositions[i].x() > TetrisProperties::maxX 
            || newPositions[i].y() < TetrisProperties::minY || newPositions[i].y() > TetrisProperties::maxY || !playingField.isEmpty(newPositions[i])) {
                return;
            } 
        }

        for (int i = 0; i < MAX_BLOCKS; i++) {
            blocks[i].updatePosition(newPositions[i]);
        }

        direction = newDirection(direction);
}
