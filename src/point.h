#pragma once

#include <cstdint>

struct Point {
  int x, y;

  bool operator==(Point& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  Point operator+(const Point& rhs) const {
    return {x + rhs.x, y + rhs.y};
  }
};
