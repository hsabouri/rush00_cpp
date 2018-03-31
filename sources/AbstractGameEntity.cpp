/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:40:08 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 14:06:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"

AbstractGameEntity::AbstractGameEntity( void ) : 
	_xPos(0), _yPos(0),
	_status(alive),
	_skin(254)
{
	return ;
}

AbstractGameEntity::AbstractGameEntity( float x, float y, unsigned char skin ) :
	_xPos(x), _yPos(y),
	_status(alive),
	_skin(skin)
{
	return ;
}

// Member functions

void		AbstractGameEntity::scroll( float amount ) {
	(void)amount;
	return ;
}
