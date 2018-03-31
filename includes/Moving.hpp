/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moving.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:48:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 16:34:25 by hsabouri         ###   ########.fr       */
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
		float			getCurrentSpeed( void ) const;

		virtual void	movement( void );

	protected:
		void		setSpeeds( float x, float y );
		void		modSpeeds( float x, float y );
		
		void		drag( void );

	private:
		float		_xSpeed;
		float		_ySpeed;
		float		_maxSpeed;
		float		_drag;
};

#endif
