#pragma once

#include <ncurses.h>
#include "point.h"

class Drawable: public Point {
  private:
    bool _is_drawn = false;
    Point* _next_location = nullptr;

  protected:
    char _symbol;

  public:
    Drawable(char symbol, int8_t x, int8_t y);
    Drawable(const Point& point, char symbol);
    Drawable(const Drawable& copy);
    ~Drawable();

    inline char symbol() const { return _symbol; }

    void draw(WINDOW* window);
    void move(const Point& diff);
    void move_to(const Point& target);
};
