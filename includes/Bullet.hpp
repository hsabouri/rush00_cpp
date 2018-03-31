/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:48:15 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 18:40:41 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BULLET_HPP
# define BULLET_HPP

# include "AbstractGameEntity.hpp"
# include "Moving.hpp"

class Bullet : public Moving {

	public:
		Bullet( float x, float y, float ySpeed );
		Bullet( void );
		Bullet( Bullet const & src);
		Bullet & operator=( Bullet const & rhs );

		void		movement( void );
		void		scroll( float amount );
};

#endif
