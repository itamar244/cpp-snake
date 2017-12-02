#pragma once
#include <cstdint>
#include <algorithm>
#include <vector>
#include <ncurses.h>
#include "drawable.h"

namespace utils {

struct BoundRect {
  const int top, right, bottom, left;
};

inline int random(int min, int max) {
  return std::rand() % (max - min) + min;
}

template<class T>
void draw_vector(WINDOW* window, std::vector<T>& vec) {
  for (auto& item : vec) {
    item.draw(window);
  }
}

bool is_point_in_rect(const Point& point, const BoundRect& rect);
Point random_point(const BoundRect& rect);

} // namespace utils
