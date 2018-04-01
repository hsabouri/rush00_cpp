/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:44:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 18:21:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef  ABSTRACTGAMEENTITY_HPP
# define ABSTRACTGAMEENTITY_HPP

enum Status {
	alive,
	dying,
	dead
};

class AbstractGameEntity {

	public:
		AbstractGameEntity( float x, float y, char *skin );
		AbstractGameEntity( void );
		AbstractGameEntity( AbstractGameEntity const & src);
		AbstractGameEntity & operator=( AbstractGameEntity const & rhs );
		virtual ~AbstractGameEntity( void );

		static int		width;
		static int		height;
		static float	mult;

		void			display( void ) const;

		int				getIntPosX( void ) const;
		int				getIntPosY( void ) const;
		int 			getOldX(void);
		int 			getOldY(void);
		void			saveCoords(int x, int y);
		float			getPosX( void ) const;
		float			getPosY( void ) const;
		char *			getSkin( void ) const;
		Status			getStatus( void ) const;

	protected:
		void			setPos( float x, float y );
		void			modPos( float x, float y );

		void			setSkin( char *skin );
		void			setStatus( Status newStatus );

		virtual void	myscroll( float amount );
	private:
		int				oldX;
		int				oldY;
		float			_xPos;
		float			_yPos;
		Status			_status;
		char *			_skin;
};

#endif
