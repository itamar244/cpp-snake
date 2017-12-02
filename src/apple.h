#pragma once

#include <cstdint>
#include <ncurses.h>
#include "drawable.h"
#include "point.h"

class Apple: public Drawable {
  private:
    bool _has_drawn = false;

  public:
    Apple(const Point& point);

    void draw(WINDOW* window);
};
