#ifndef Vector2D_H
#define Vector2D_H

#include "Arduino.h"

class Vector2D
{
public:        
  Vector2D() : x_(0), y_(0) {}

  Vector2D(int x, int y) : x_(x), y_(y) {}  

  int x() const {
      return x_;
  }

  int y() const {
      return y_;
  }

  bool operator==(const Vector2D& other) const {
      return x_ == other.x() && y_ == other.y();
  }

  bool operator<(const Vector2D& other) const {
      if (x_ == other.x()) {
          return y_ < other.y();
      }
      return x_ < other.x();
  }

private:
    int x_;

    int y_;

  
};

#endif