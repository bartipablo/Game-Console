#ifndef Vector2D_H
#define Vector2D_H

#include "Arduino.h"

class Vector2D
{
public:        
  const int x;

  const int y;

  Vector2D() : x(0), y(0) {}

  Vector2D(int x, int y) : x(x), y(y) {}  

  bool operator==(const Vector2D& other) const {
      return x == other.x && y == other.y;
  }

  bool operator<(const Vector2D& other) const {
      if (x == other.x) {
          return y < other.y;
      }
      return x < other.x;
    }
  
private:

};

#endif