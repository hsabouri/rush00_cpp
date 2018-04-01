/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ennemy.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:26:10 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 07:59:38 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include <AbstractGameEntity.hpp>
#include <Moving.hpp>
#include <Ennemy.hpp>
#include <Bullet.hpp>

Ennemy::Ennemy( void ) :
	Moving( 0.0f,
			0.0f,
			(char *)"E",
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
			(char *)"E",
			xSpeed,
			ySpeed,
			10.0f * AbstractGameEntity::mult,
			0.0f)
{
	this->setSpeeds(xSpeed, ySpeed);
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

// Member functions

int 	Ennemy::collide(Bullet **bullets, size_t size) {
	int touched = -1;
	int this_pos_x = this->getIntPosX();
	int this_pos_y = this->getIntPosY();

	for (size_t i = 0; i < size; i++) {
		int bullet_pos_x = bullets[i]->getIntPosX();
		int bullet_pos_y = bullets[i]->getIntPosY();

		if (this_pos_x == bullet_pos_x && this_pos_y < bullet_pos_y + 1 && this_pos_x > bullet_pos_y - 1) {
			this->setStatus(dying);
			touched = i;
			delete bullets[i];
			bullets[i] = NULL;
			break;
		}
	}
	return touched;
	// returns -1 or the id of the touched element, the element is destroyed and setted to null
}

// Implementations

void	Ennemy::movement( void ) {
    this->saveCoords(getIntPosX(), getIntPosY());
	this->modPos(this->getSpeedX(), this->getSpeedY());
	return ;
}

void	Ennemy::myscroll( float amount ) {
	this->modPos(-amount, -amount);
	return ;
}
