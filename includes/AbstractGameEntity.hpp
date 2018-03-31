/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:44:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 15:22:03 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ABSTRACTGAMEENTITY_HPP
# define ABSTRACTGAMEENTITY_HPP

enum Status {
	alive,
	dying,
	dead
};

class AbstractGameEntity {

	public:
		AbstractGameEntity( float x, float y, unsigned char skin );
		AbstractGameEntity( void );
		AbstractGameEntity( AbstractGameEntity const & src);
		AbstractGameEntity & operator=( AbstractGameEntity const & rhs );

		static int		width;
		static int		height;
		static float	mult;

		void			display( void ) const;

		int				getIntPosX( void ) const;
		int				getIntPosY( void ) const;
		float			getPosX( void ) const;
		float			getPosY( void ) const;
		unsigned char	getSkin( void ) const;
		Status			getStatus( void ) const;

	protected:
		void			setPos( float x, float y );
		void			modPos( float x, float y );

		void			setSkin( unsigned char skin );
		void			setStatus( Status newStatus );

		virtual void	scroll( float amount );

	private:
		float			_xPos;
		float			_yPos;

		Status			_status;

		unsigned char	_skin;
};

#endif
