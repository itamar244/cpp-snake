#include "utils.h"

namespace utils {

bool is_point_in_rect(const Point& point, const BoundRect& rect) {
  return (
    point.x >= rect.left && point.x <= rect.right
    && point.y >= rect.top && point.y <= rect.bottom
  );
}

Point random_point(const BoundRect& rect) {
  return Point{
    static_cast<int8_t>(random(rect.left, rect.right)),
    static_cast<int8_t>(random(rect.top, rect.bottom)),
  };
}

} // namespace utils
