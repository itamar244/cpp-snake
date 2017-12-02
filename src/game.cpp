#include "game.h"
#include <utility>
#include "direction.h"

Game::Game(WINDOW* window, int width, int height)
  : _window{window}
  , _snake{
      static_cast<int8_t>(utils::random(width / 4, width - width / 4)),
      static_cast<int8_t>(utils::random(height / 4, height - height / 4)),
      static_cast<Direction>(utils::random(0, 3))
    }
  , _width{width}
  , _height{height}
  , _turn{0} {}

void Game::play() {
  if (!_is_running) return;
  _turn++;

  Point snake_head = _snake.get_head();
  Direction input = input_to_direction(getch());

  if (input != Direction::Invalid) {
    _snake.set_dir(input);
  }
  
  if (_turn % 40 == 0 && _apples.size() < 3) {
    _apples.push_back(
      Apple(utils::random_point(get_bound_rect()))
    );
  }
  for (auto apple = _apples.begin(); apple < _apples.end(); apple++) {
    if (snake_head == *apple) {
      _apples.erase(apple);
      _snake.add_part();
    }
  }
  _snake.move(_window);
  _snake.draw(_window);
  utils::draw_vector<Apple>(_window, _apples);
  if (
    _snake.is_touching_itself() 
    || !is_point_in_rect(_snake.get_head(), get_bound_rect())
  ) {
    _is_running = false;
  }
}
