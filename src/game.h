#pragma once

#include <cstdint>
#include <vector>
#include <ncurses.h>
#include "apple.h"
#include "utils.h"
#include "snake.h"

class Game {
  private:
    WINDOW* _window;
    Snake _snake;
    std::vector<Apple> _apples;
    int _width, _height, _turn;
    bool _is_running = true;
    

  public:
    Game(WINDOW* window, int width, int height);

    inline bool is_running() const { return _is_running; };
    inline utils::BoundRect get_bound_rect() const { return {1, _width - 1, _height - 1, 1}; }

    void play();
};
