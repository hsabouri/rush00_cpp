/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:04:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 23:19:04 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP
# include <ncurses.h>

class Window {
	public:
		Window( void );
		Window( const Window &src );
		~Window( void );
		Window &operator=( const Window &src );

		void init();
		void refresh();
		void updateDisplay(int x, int y, const char *str, const char type);
		void init_main_window();
		void init_menu_window(void);
		void clear(void);
		void updateScore(size_t score);
		void init_color();

	private:
		WINDOW *win;
		WINDOW *menu;
};

#endif
