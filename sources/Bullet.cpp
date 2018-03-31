/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:00:57 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 18:19:51 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"
#include "Moving.hpp"
#include "Bullet.hpp"

Bullet::Bullet( void ) : Moving( 0.0f,
								 0.0f,
								 196,
								 1.0f * AbstractGameEntity::mult,
								 0.0f,
								 1.0f * AbstractGameEntity::mult,
								 0.0f)
{
	return ;
}

Bullet::Bullet(float x, float y, float ySpeed) :
	Moving( x,
			y,
			196,
			1.0f * AbstractGameEntity::mult,
			ySpeed,
			1.0f * AbstractGameEntity::mult,
			0.0f)

{
	return ;
}

Bullet::Bullet( Bullet const & src ) : Moving(src) {
	return ;
}

Bullet & Bullet::operator=( Bullet const & rhs ) {
	this->setSpeeds(rhs.getSpeedX(), rhs.getSpeedY());
	this->setMaxSpeed(rhs.getMaxSpeed());
	return *this;
}

// Implementations

void	Bullet::movement( void ) {
	this->modPos(this->getSpeedX(), this->getSpeedY());
	return ;
}

void	Bullet::scroll( float amount ) {
	(void)amount;
	return ;
}
