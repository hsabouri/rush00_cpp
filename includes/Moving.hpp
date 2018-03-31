/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moving.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:48:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 18:31:56 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MOVING_HPP
# define MOVING_HPP

# include "AbstractGameEntity.hpp"

class Moving : public AbstractGameEntity {

	public:
		Moving( float x, float y, unsigned char skin, float xSpeed, float ySpeed, float max, float drag );
		Moving( void );
		Moving( Moving const & src);
		Moving & operator=( Moving const & rhs );

		float			getSpeedX( void ) const;
		float			getSpeedY( void ) const;
		float			getDrag( void ) const;
		float			getMaxSpeed( void ) const;

		virtual void	movement( void );

	protected:
		void		setSpeeds( float x, float y );
		void		setMaxSpeed( float max );
		void		modSpeeds( float x, float y );
		
		void		drag( void );
		// Slows down the entity

	private:
		float		_xSpeed;
		float		_ySpeed;
		float		_maxSpeed;
		float		_drag;
};

#endif
