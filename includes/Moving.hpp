/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moving.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:48:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 14:29:56 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MOVING_HPP
# define MOVING_HPP

# include "AbstractGameEntity.hpp"

class Moving : public AbstractGameEntity {

	public:
		Moving( float x, float y, char *skin, float xSpeed, float ySpeed, float xmax, float ymax, float drag );
		Moving( void );
		Moving( Moving const & src);
		virtual ~Moving( void );
		Moving & operator=( Moving const & rhs );

		float			getSpeedX( void ) const;
		float			getSpeedY( void ) const;
		float			getDrag( void ) const;
		float			getMaxSpeed( void ) const;
		void			setMaxSpeed( float max );
		float			getCurrentSpeed( void ) const;
		virtual void	movement( void );

	protected:
		void		setSpeeds( float x, float y );
		void		modSpeeds( float x, float y );
		
		void		drag( void );
		// Slows down the entity

	private:
		float		_xSpeed;
		float		_ySpeed;
		float		_xMaxSpeed;
		float		_yMaxSpeed;
		float		_drag;
};

#endif
