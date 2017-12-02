#include <ctime>
#include <algorithm>
#include <ncurses.h>
#include "game.h"

int main() {
	std::srand(std::time(0));

	int height, width;

	initscr();
	noecho();
	cbreak();
	curs_set(0);
	nodelay(stdscr, true);
	keypad(stdscr, true);

	getmaxyx(stdscr, height, width);

	WINDOW* window = newwin(height, width / 1.5, 0, 0);
	box(window, 0, 0);

	Game game(window, window->_maxx, window->_maxy);

	while (game.is_running()) {
		game.play();
		wrefresh(window);
		napms(100);
	}

	endwin();
	return 0;
}
