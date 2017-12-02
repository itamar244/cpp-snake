#pragma once

#include <cmath>
#include <cstdint>
#include "point.h"

enum class Direction {
  Up,
  Right,
  Down,
  Left,
  Invalid,
};

Point direction_to_point_diff(Direction direction);
Direction input_to_direction(int ch);

inline bool is_opposite_direction(Direction dir1, Direction dir2) {
  return std::abs(static_cast<int>(dir1) - static_cast<int>(dir2)) == 2;
}
