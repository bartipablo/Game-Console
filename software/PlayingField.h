#ifndef Playing_Field_H
#define Playing_Field_H

#include "Arduino.h"
#include "Block.h"
#include "Vector2D.h"
#include <map>
#include <vector>
#include "optional.hpp"

class PlayingField {
public:
    PlayingField();        
  
    bool isEmpty(Vector2D position) const;

    bool isEmptyPositions(std::vector<Vector2D> positions);

    bool isEmptyPositionsBelow(std::vector<Vector2D> positions);

    void insertBlocks(std::vector<Block> blocks);

    void clearLine(int line);

    void clearLines(std::vector<int> lines);

    void dropFloatingBlocks();

    void swapTwoLines(int i, int j);

    Block getFromPosition(Vector2D position) const;

    std::vector<Vector2D> getAllKeys() const;

    bool lineIsEmpty(int lineNo);

private:
    std::map < Vector2D, tl::optional<Block> > fields;
};

#endif