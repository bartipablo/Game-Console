#include "Arduino.h"
#include "PlayingField.h"

PlayingField::PlayingField() {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
        fields[Vector2D(x, y)] = tl::nullopt;
    }
  }
}

bool PlayingField::isEmpty(Vector2D position) {
    return fields[position] == tl::nullopt;
}