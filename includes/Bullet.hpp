/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:48:15 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:38:02 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BULLET_HPP
# define BULLET_HPP

# include "AbstractGameEntity.hpp"
# include "Moving.hpp"
# include "Window.hpp"

class Bullet : public Moving {

	public:
		Bullet( float x, float y, float ySpeed );
		Bullet(float x, float y, float xSpeed, float ySpeed, char *skin, float drag);
		Bullet( void );
		Bullet( Bullet const & src );
		~Bullet( void );
		Bullet & operator=( Bullet const & rhs );

		void		movement( void );
};

#endif
