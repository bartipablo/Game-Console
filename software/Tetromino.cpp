#include "Tetromino.h"

std::vector<Block> Tetromino::getBlocks()
{
    return std::vector<Block>(blocks, blocks + MAX_BLOCKS);
}

void Tetromino::move(int x, int y)
{
    for (auto &block : blocks)
    {
        Vector2D actualPosition = block.getPosition();
        Vector2D newPosition = Vector2D(actualPosition.x() + x, actualPosition.y() + y);

        if (newPosition.x() < TetrisProperties::minX || newPosition.x() > TetrisProperties::maxX || newPosition.y() < TetrisProperties::minY || newPosition.y() > TetrisProperties::maxY || !playingField.isEmpty(newPosition))
        {
            return;
        }
    }

    for (auto &block : blocks)
    {
        Vector2D actualPosition = block.getPosition();
        Vector2D newPosition = Vector2D(actualPosition.x() + x, actualPosition.y() + y);
        block.updatePosition(newPosition);
    }
}

bool Tetromino::isReadyToSettle()
{
    for (auto &block : blocks)
    {
        Vector2D actualPosition = block.getPosition();
        Vector2D bottomPosition = Vector2D(actualPosition.x(), actualPosition.y() - 1);
        if (!playingField.isEmpty(bottomPosition))
        {
            return false;
        }
    }
    return true;
}
