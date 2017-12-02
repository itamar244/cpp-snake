#pragma once

#include <cstdint>
#include <vector>
#include "direction.h"
#include "drawable.h"
#include "point.h"

class Snake {
  private:
    uint8_t _queued_parts = 0;
    std::vector<Drawable> _tail;
    Direction _direction;

    inline Drawable& _head() { return _tail.front(); }

  public:
    Snake(int8_t x, int8_t y, Direction direction);
    
    inline Point get_head() const { return _tail.front(); }

    void add_part();
    void draw(WINDOW* window);
    bool is_touching_itself();
    void move(WINDOW* window);
    void set_dir(Direction new_direction);
};
