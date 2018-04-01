/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:48:15 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 06:35:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BULLET_HPP
# define BULLET_HPP

# include "AbstractGameEntity.hpp"
# include "Moving.hpp"
#include <Window.hpp>

class Bullet : public Moving {

	public:
		Bullet( float x, float y, float ySpeed );
		Bullet( void );
		Bullet( Bullet const & src);
		Bullet & operator=( Bullet const & rhs );

		void		movement( void );
		void		myscroll( float amount );
		void		remove_self(Window &win);
};

#endif
