/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:04:27 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 23:25:58 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Window.hpp"
#include "Bullet.hpp"

#include <sstream>

Window::Window(void) {
}

Window::Window(const Window &src) {
    *this = src;
}

Window &Window::operator=(const Window &src) {
	this->win = src.win;
	this->menu = src.menu;
    return *this;
}

Window::~Window(void) {
	return ;
}

void Window::init(void) {
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	scrollok(stdscr, TRUE);
	init_main_window();
	init_menu_window();
	init_color();
}

void Window::init_main_window(void) {
	win = subwin(stdscr, 40, 200, 1, 4);
	box(win, ACS_VLINE, ACS_HLINE);
}

void Window::init_menu_window(void) {
	menu = subwin(stdscr, 40, 60, 1, 215);
	mvwprintw(menu, 5, 26, "FT_RETRO");
	mvwprintw(menu, 10, 10, "SCORE :\t\t");
	mvwprintw(menu, 15, 10, "Z Q S D to move");
	mvwprintw(menu, 17, 10, "SPACEBAR for special attack");
	mvwprintw(menu, 20, 10, "DOWNARROW to quit");
}

void Window::init_color(void) {
	start_color();
	init_pair(10, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_RED, COLOR_BLACK);
	init_pair(12, COLOR_GREEN, COLOR_BLACK);
}

void Window::refresh(void) {
	wrefresh(this->win);
	wrefresh(this->menu);
}

void Window::clear(void) {
	wclear(this->win);
}

void Window::updateDisplay(int x, int y, const char *str, const char type) {
	if (type == 'p')
		wattron(win, COLOR_PAIR(10));
	if (type == 'b')
		wattron(win, COLOR_PAIR(12));
	if (type == 'e')
		wattron(win, COLOR_PAIR(11));
	mvwprintw(this->win, y, x, str);
}

void Window::updateScore(size_t score) {
	std::string s;
	std::stringstream out;
	out << score;
	s = out.str();

	mvwprintw(this->menu, 10, 20, s.c_str());
}