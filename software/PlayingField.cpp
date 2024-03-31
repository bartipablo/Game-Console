#include "Arduino.h"
#include "PlayingField.h"

PlayingField::PlayingField() {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
        fields[Vector2D(x, y)] = tl::nullopt;
    }
  }
}

bool PlayingField::isEmpty(Vector2D position) const {
    auto it = fields.find(position);
    return (it == fields.end()) || !it->second.has_value();
}

bool PlayingField::isEmptyPositions(std::vector<Vector2D> positions) {
    for (const auto& pos : positions) {
        if (!isEmpty(pos)) {
            return false;
        }
    }
    return true;
}

bool PlayingField::isEmptyPositionsBelow(std::vector<Vector2D> positions) {
    for (const auto &position : positions) {
        Vector2D belowPosition = Vector2D(position.x(), position.y() + 1);
        if (!isEmpty(belowPosition)) {
            return false; 
        }
    }
    return true;   
}

void PlayingField::insertBlocks(std::vector<Block> blocks) {
    for (const auto& block : blocks) {
        Vector2D position = block.getPosition();
        fields[position] = tl::make_optional<Block>(block);
    }
}

void PlayingField::clearLine(int line) {
    for (int j = 0; j < 10; j++) {
        fields[Vector2D(j, line)] = tl::nullopt;
    }
}

void PlayingField::clearLines(std::vector<int> lines) {
    for (int line : lines) {
        clearLine(line);
    }
}


void PlayingField::dropFloatingBlocks() {
    int previousLinePtr = 19;
    int nextLinePtr = 18;


    while (nextLinePtr >= 0) {
          if (lineIsEmpty(previousLinePtr) && !lineIsEmpty(nextLinePtr)) { //ok.
              swapTwoLines(previousLinePtr, nextLinePtr);
              previousLinePtr--;
              nextLinePtr--;
          }
          else if (lineIsEmpty(previousLinePtr) && lineIsEmpty(nextLinePtr)) { //ok.
              nextLinePtr--;
          }
          else if (!lineIsEmpty(previousLinePtr) && lineIsEmpty(nextLinePtr)) {
              previousLinePtr--;
          }
          else if (!lineIsEmpty(previousLinePtr) && !lineIsEmpty(nextLinePtr)) {
              previousLinePtr--;
              nextLinePtr--;            
          }
    }
}


void PlayingField::swapTwoLines(int i, int j) {

    for (int k = 0; k < 10; k++) {
        tl::optional<Block>& block1 = fields[Vector2D(k, i)];
        tl::optional<Block>& block2 = fields[Vector2D(k, j)];
        
        if (block1.has_value() && block2.has_value()) {
            block1.value().updatePosition(Vector2D(k, j));
            block2.value().updatePosition(Vector2D(k, i));
        }
        else if (block1.has_value() && !block2.has_value()) {
            block1.value().updatePosition(Vector2D(k, j)); 
            fields[Vector2D(k, j)] = block1;        
            fields[Vector2D(k, i)] = tl::nullopt;
        }
        else if (!block1.has_value() && block2.has_value()) {
            block2.value().updatePosition(Vector2D(k, i));
            fields[Vector2D(k, i)] = block2;        
            fields[Vector2D(k, j)] = tl::nullopt;
        }
        
        
    }
}

std::vector<Vector2D> PlayingField::getAllKeys() const {
    std::vector<Vector2D> keys;
    for (const auto& pair : fields) {
        keys.push_back(pair.first);
    }
    return keys;
}


Block PlayingField::getFromPosition(Vector2D position) const {
    auto it = fields.find(position);
    return it->second.value(); 
}


bool PlayingField::lineIsEmpty(int lineNo) {
    for (int x = 0; x < 10; x++) {
        if (!isEmpty(Vector2D(x, lineNo))) {
            return false;
        }
    }
    return true;
}