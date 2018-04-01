/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:04:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 16:06:47 by hsabouri         ###   ########.fr       */
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
		void updateDisplay(int x, int y, const char *str);
		void init_main_window();
		void clear(void);

	private:
		WINDOW *win;
};

#endif
