/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:04:27 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 16:06:11 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include "Window.hpp"
#include "Bullet.hpp"

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
}

void Window::init_main_window(void) {
	win = subwin(stdscr, 40, 200, 1, 4);
	wbkgd(win, COLOR_PAIR(255));
	box(win, ACS_VLINE, ACS_HLINE);
}

void Window::refresh(void) {
	wrefresh(this->win);
}

void Window::clear(void) {
	wclear(this->win);
}

void Window::updateDisplay(int x, int y, const char *str) {
	mvwprintw(this->win, y, x, str);
}
