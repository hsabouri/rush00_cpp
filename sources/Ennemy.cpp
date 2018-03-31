/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:26:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 17:41:17 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"
#include "Moving.hpp"
#include "Ennemy.hpp"

Ennemy::Ennemy( void ) :
	Moving( 0.0f,
			0.0f,
			60,
			-1.0f * AbstractGameEntity::mult,
			0.0f,
			10.0f * AbstractGameEntity::mult,
			0.0f)
{
	return ;
}

Ennemy::Ennemy( float x, float y, float xSpeed, float ySpeed ) :
	Moving( x,
			y,
			196,
			xSpeed,
			ySpeed,
			10.0f * AbstractGameEntity::mult,
			0.0f)
{
	return ;
}

Ennemy::Ennemy( Ennemy const & src ) : Moving(src) {
	return ;
}

Ennemy & Ennemy::operator=( Ennemy const & rhs ) {
	this->setSpeeds(rhs.getSpeedX(), rhs.getSpeedY());
	this->setMaxSpeed(rhs.getMaxSpeed());
	return *this;
}

// Implementations

void	Ennemy::movement( void ) {
	this->modPos(this->getSpeedX(), this->getSpeedY());
	return ;
}

void	Ennemy::scroll( float amount ) {
	this->modPos(-amount, -amount);
	return ;
}
