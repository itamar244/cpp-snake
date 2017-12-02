#include "apple.h"

Apple::Apple(const Point& point) : Drawable{point, '$'} {}

void Apple::draw(WINDOW* window) {
  if (!_has_drawn) {
    _has_drawn = true;
    Drawable::draw(window);
  }
}
