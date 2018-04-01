/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:00:57 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:35:49 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"
#include "Moving.hpp"
#include "Bullet.hpp"
#include <Window.hpp>

Bullet::Bullet( void ) : Moving( 0.0f,
								 0.0f,
								 (char *)"-",
								 1.0f * AbstractGameEntity::mult,
								 0.0f,
								 1.0f * AbstractGameEntity::mult,
								 1.0f * AbstractGameEntity::mult,
								 0.0f)
{
	return ;
}

Bullet::Bullet(float x, float y, float ySpeed) :
	Moving( x,
			y,
			(char *)"-",
			0.5f * AbstractGameEntity::mult,
			ySpeed,
			1.0f * AbstractGameEntity::mult,
			1.0f * AbstractGameEntity::mult,
			0.0f)
{
	return ;
}

Bullet::Bullet(float x, float y, float xSpeed, float ySpeed, char *skin, float drag) :
	Moving( x,
			y,
			skin,
			xSpeed,
			ySpeed,
			1.0f * AbstractGameEntity::mult,
			1.0f * AbstractGameEntity::mult,
			drag)
{
	return ;
}

Bullet::Bullet( Bullet const & src ) : Moving(src) {
	return ;
}

Bullet::~Bullet( void ) {
	return ;
}

Bullet & Bullet::operator=( Bullet const & rhs ) {
	this->setSpeeds(rhs.getSpeedX(), rhs.getSpeedY());
	this->setMaxSpeed(rhs.getMaxSpeed());
	return *this;
}

// Implementations

void	Bullet::movement( void ) {
	this->drag();
    this->saveCoords(getIntPosX(), getIntPosY());
	this->modPos(this->getSpeedX(), this->getSpeedY());
	if ((this->getSpeedX() < 0.0001f && this->getSpeedX() < 0.0001f) || this->getIntPosX() >= 198) {
		this->setStatus(dead);
	}
	return ;
}
