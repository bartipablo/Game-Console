#ifndef Block_H
#define Block_H

#include "../Vector2D.h"


/**
 * @brief Class representing a single block in tetris.
 * 
 */
class Block {
public:
  Block() : color(0), position(Vector2D()) {}

  Block(int color, Vector2D position) : color(color), position(position) {}

  int getColor() const;

  Vector2D getPosition() const;

  void updatePosition(const Vector2D newPosition);

private:
  int color;
  Vector2D position;
};

#endif