/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:24:53 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 18:40:47 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ENNEMY_HPP
# define ENNEMY_HPP

# include "AbstractGameEntity.hpp"
# include "Moving.hpp"

class Ennemy : public Moving {

	public:
		Ennemy( float x, float y, float xSpeed, float ySpeed );
		Ennemy( void );
		Ennemy( Ennemy const & src);
		Ennemy & operator=( Ennemy const & rhs );

		void		movement( void );
		void		scroll( float amount );
};

#endif
