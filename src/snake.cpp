#include "snake.h"
#include <utility>
#include "utils.h"

namespace {

inline void clear_point(WINDOW* window, const Point& point) {
  mvwaddch(window, point.y, point.x, ' ');
}

} // namespace

Snake::Snake(int8_t x, int8_t y, Direction direction)
  : _tail{{Drawable('@', x, y)}}
  , _direction{direction} {}

void Snake::add_part() {
  _queued_parts++;
}

void Snake::draw(WINDOW* window) {
  utils::draw_vector<Drawable>(window, _tail);
}

bool Snake::is_touching_itself() {
  for (int i = 1; i < _tail.size(); i++) {
    if (_head() == _tail.at(i)) {
      return true;
    }
  }
  return false;
}


void Snake::move(WINDOW* window) {
  const uint8_t tail_size = _tail.size();
  if (_queued_parts > 0) {
    _tail.reserve(_queued_parts);
    for (; _queued_parts > 0; _queued_parts--) {
      _tail.push_back(Drawable(_tail[tail_size - 1], 'o'));
    }
  }
  for (int8_t i = tail_size - 1; i > 0; i--) {
    clear_point(window, _tail[i]);
    _tail[i].move_to(_tail[i - 1]);
  }
  clear_point(window, _head());
  _head().move(direction_to_point_diff(_direction));
}

void Snake::set_dir(Direction next_direction) {
  if (!is_opposite_direction(_direction, next_direction)) {
    _direction = next_direction;
  }
}
