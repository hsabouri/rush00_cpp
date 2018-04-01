/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 09:57:23 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:45:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP
# include "Moving.hpp"
# include "Bullet.hpp"
# include "Window.hpp"
# include <Ennemy.hpp>

class Player : public Moving {
	public:
		Player( void );
		Player( float x, float y );
		Player(const Player &src);
		~Player( void );
		Player &operator=(const Player &src);

		void	input(Bullet **bullets, size_t buffer_size, size_t &last_bullet);

		int 	collide(Ennemy **ennemies, size_t size);
		void	movement( void );
		void	shoot(Bullet **buffer, size_t size, size_t & last_bullet);
		void	shoot_bomb(Bullet **buffer, size_t size, size_t & last_bullet);

	private:
		int cooldown;
};

#endif
