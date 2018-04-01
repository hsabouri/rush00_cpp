/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moving.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:13:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 07:57:03 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"
#include "Moving.hpp"

// Coplien

Moving::Moving( void ) : AbstractGameEntity(),
	_xSpeed(0.0f), _ySpeed(0.0f),
	_maxSpeed(1.0f * AbstractGameEntity::mult),
	_drag(0.1f * AbstractGameEntity::mult)
{
	return ;
}

Moving::Moving( float x, float y, char *skin, float xSpeed, float ySpeed, float max, float drag ) :
	AbstractGameEntity(x, y, skin),
	_xSpeed(xSpeed * AbstractGameEntity::mult),
	_ySpeed(ySpeed * AbstractGameEntity::mult),
	_maxSpeed(max * AbstractGameEntity::mult),
	_drag(drag * AbstractGameEntity::mult)
{
	return ;
}

Moving::Moving( Moving const & src ) :
	AbstractGameEntity(src),
	_xSpeed(src.getSpeedX()), _ySpeed(src.getSpeedY()),
	_maxSpeed(src.getMaxSpeed()),
	_drag(src.getDrag())
{
	return ;
}

Moving & Moving::operator=( Moving const & rhs ) {
	this->_xSpeed = rhs.getSpeedX();
	this->_ySpeed = rhs.getSpeedY();
	this->_maxSpeed = rhs.getMaxSpeed();
	this->_drag = rhs.getDrag();
	return *this;
}

// Member functions

float			Moving::getSpeedX( void ) const {
	return (this->_xSpeed);
}

float			Moving::getSpeedY( void ) const {
	return (this->_ySpeed);
}

float			Moving::getDrag( void ) const {
	return (this->_drag);
}

float			Moving::getMaxSpeed( void ) const {
	return (this->_maxSpeed);
}

void			Moving::setSpeeds( float x, float y ) {
	if (x > this->_maxSpeed) {
		this->_xSpeed = this->_maxSpeed;
	} else if (x < - this->_maxSpeed ) {
		this->_xSpeed = - this->_maxSpeed;
	} else {
		this->_xSpeed = x;
	}
	if (y > this->_maxSpeed) {
		this->_ySpeed = this->_maxSpeed;
	} else if (y < - this->_maxSpeed ) {
		this->_ySpeed = - this->_maxSpeed;
	} else {
		this->_ySpeed = y;
	}
	return ;
}

void			Moving::setMaxSpeed( float max ) {
	this->_maxSpeed = max;
	return ;
}

void			Moving::modSpeeds( float x, float y ) {
	x += this->_drag; //
	y += this->_drag; // Removing drag effect

	if (this->_xSpeed + x > this->_maxSpeed) {
		this->_xSpeed = this->_maxSpeed;
	} else if (this->_xSpeed + x < - this->_maxSpeed ) {
		this->_xSpeed = - this->_maxSpeed;
	} else {
		this->_xSpeed += x;
	}
	if (this->_ySpeed + y > this->_maxSpeed) {
		this->_ySpeed = this->_maxSpeed;
	} else if (this->_xSpeed + y < - this->_maxSpeed ) {
		this->_ySpeed = - this->_maxSpeed;
	} else {
		this->_ySpeed += y;
	}
	return ;
}

void			Moving::drag( void ) {
	if (this->_xSpeed > 0.00001f) {
		if (this->_xSpeed - this->_drag > 0.00001f) {
			this->_xSpeed -= this->_drag;
		} else {
			this->_xSpeed = 0.0f;
		}
	} else {
		if (this->_xSpeed + this->_drag < -0.00001f) {
			this->_xSpeed += this->_drag;
		} else {
			this->_xSpeed = 0.0f;
		}
	}
	if (this->_ySpeed > 0.00001f) {
		if (this->_ySpeed - this->_drag > 0.00001f) {
			this->_ySpeed -= this->_drag;
		} else {
			this->_ySpeed = 0.0f;
		}
	} else {
		if (this->_ySpeed + this->_drag < -0.00001f) {
			this->_ySpeed += this->_drag;
		} else {
			this->_ySpeed = 0.0f;
		}
	}
}

// Default movement behavior
void		Moving::movement( void ) {
	this->drag();
	this->modPos(this->_xSpeed, this->_ySpeed);
	return ;
}
