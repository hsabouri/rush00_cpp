#include <iostream>

#include <Window.hpp>
#include <Bullet.hpp>

Window::Window(void) {
}

Window::Window(const Window &src) {
    *this = src;
}

Window &Window::operator=(const Window &src) {
	this->win = src.win;
    return *this;
}

Window::~Window(void) {
}

void Window::init(void) {
	initscr();                                                       
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	scrollok(stdscr, TRUE);
	init_main_window();
}

void Window::init_main_window(void) {
	win = subwin(stdscr, 40, 200, 1, 4);
	wbkgd(win, COLOR_PAIR(255));
	box(win, ACS_VLINE, ACS_HLINE);
}

void Window::refresh(void) {
	wrefresh(win);
}

void Window::updateDisplay(int x, int y, const char *str) {
	mvwprintw(win, x, y, str);
}
