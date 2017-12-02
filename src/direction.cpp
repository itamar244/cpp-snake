#include "direction.h"
#include <ncurses.h>

Point direction_to_point_diff(Direction direction) {
  switch(direction) {
    case Direction::Up:
      return {0, -1};
    case Direction::Right:
      return {1, 0};
    case Direction::Down:
      return {0, 1};
    case Direction::Left:
      return {-1, 0};
    default:
      return {0, 0};
  }
}

Direction input_to_direction(int ch) {
  switch (ch) {
    case KEY_UP:
      return Direction::Up;
    case KEY_RIGHT:
      return Direction::Right;
    case KEY_DOWN:
      return Direction::Down;
    case KEY_LEFT:
      return Direction::Left;
    default:
      return Direction::Invalid;
  }
}
