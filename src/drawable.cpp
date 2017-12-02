#include "drawable.h"

Drawable::Drawable(char symbol, int8_t x, int8_t y)
  : Point{x, y}
  , _symbol{symbol} {}

Drawable::Drawable(const Point& point, char symbol)
  : Point{point}
  , _symbol{symbol} {}

Drawable::Drawable(const Drawable& copy) {
  if (copy._next_location != nullptr) {
    _next_location = new Point(*copy._next_location);
  }
}

Drawable::~Drawable() {
  if (_next_location != nullptr) delete _next_location;
}

void Drawable::draw(WINDOW* window) {
  if (_next_location != nullptr) {
    x = _next_location->x;
    y = _next_location->y;
    _is_drawn = false;
    delete _next_location;
  }
  if (!_is_drawn) {
    mvwaddch(window, y, x, _symbol);
    _is_drawn = true;
  }
}

void Drawable::move(const Point& diff) {
  move_to(*this + diff);
}

void Drawable::move_to(const Point& target) {
  _next_location = new Point(target);
}
