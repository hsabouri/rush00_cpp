/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:00:57 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 07:59:46 by jde-maga         ###   ########.fr       */
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
								 0.0f)
{
	return ;
}

Bullet::Bullet(float x, float y, float ySpeed) :
	Moving( x,
			y,
			(char *)"-",
			1.0f * AbstractGameEntity::mult,
			ySpeed,
			1.0f * AbstractGameEntity::mult,
			0.0f)
{
		this->setSpeeds(0.0f, ySpeed);
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
    this->saveCoords(getIntPosX(), getIntPosY());
	this->modPos(this->getSpeedX(), this->getSpeedY());
	return ;
}

void	Bullet::myscroll( float amount ) {
	(void)amount;
	return ;
}

void	Bullet::remove_self(Window &win) {
	win.updateDisplay(getOldX(), getOldY(), " ");
}