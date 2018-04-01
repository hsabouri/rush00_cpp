/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moving.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:13:42 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 18:28:16 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"
#include <iostream>
#include "Moving.hpp"

// Coplien

Moving::Moving( void ) : AbstractGameEntity(),
	_xSpeed(0.0f), _ySpeed(0.0f),
	_xMaxSpeed(1.0f * AbstractGameEntity::mult),
	_yMaxSpeed(0.7f * AbstractGameEntity::mult),
	_drag(0.01f * AbstractGameEntity::mult)
{
	return ;
}

Moving::Moving( float x, float y, char *skin, float xSpeed, float ySpeed, float xmax, float ymax, float drag ) :
	AbstractGameEntity(x, y, skin),
	_xSpeed(xSpeed * AbstractGameEntity::mult),
	_ySpeed(ySpeed * AbstractGameEntity::mult),
	_xMaxSpeed(xmax * AbstractGameEntity::mult),
	_yMaxSpeed(ymax * AbstractGameEntity::mult),
	_drag(drag * AbstractGameEntity::mult)
{
	return ;
}

Moving::Moving( Moving const & src ) :
	AbstractGameEntity(src),
	_xSpeed(src.getSpeedX()), _ySpeed(src.getSpeedY()),
	_xMaxSpeed(src.getMaxSpeed()),
	_yMaxSpeed(src.getMaxSpeed()),
	_drag(src.getDrag())
{
	return ;
}

Moving & Moving::operator=( Moving const & rhs ) {
	this->_xSpeed = rhs.getSpeedX();
	this->_ySpeed = rhs.getSpeedY();
	this->_xMaxSpeed = rhs.getMaxSpeed();
	this->_yMaxSpeed = rhs.getMaxSpeed();
	this->_drag = rhs.getDrag();
	return *this;
}

Moving::~Moving( void ) {
	return ;
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
	return (this->_xMaxSpeed);
}

void			Moving::setSpeeds( float x, float y ) {
	if (x > this->_xMaxSpeed) {
		this->_xSpeed = this->_xMaxSpeed;
	} else if (x < - this->_xMaxSpeed ) {
		this->_xSpeed = - this->_xMaxSpeed;
	} else {
		this->_xSpeed = x;
	}
	if (y > this->_yMaxSpeed) {
		this->_ySpeed = this->_yMaxSpeed;
	} else if (y < - this->_yMaxSpeed ) {
		this->_ySpeed = - this->_yMaxSpeed;
	} else {
		this->_ySpeed = y;
	}
	return ;
}

void			Moving::setMaxSpeed( float max ) {
	this->_xMaxSpeed = max;
	this->_yMaxSpeed = max;
	return ;
}

void			Moving::modSpeeds( float x, float y ) {
	if (this->_xSpeed + x > this->_xMaxSpeed) {
		this->_xSpeed = this->_xMaxSpeed;
	} else if (this->_xSpeed + x < - this->_xSpeed ) {
		this->_xSpeed = - this->_xMaxSpeed;
	} else {
		this->_xSpeed += x;
	}
	if (this->_ySpeed + y > this->_yMaxSpeed) {
		this->_ySpeed = this->_yMaxSpeed;
	} else if (this->_ySpeed + y < - this->_yMaxSpeed ) {
		this->_ySpeed = - this->_yMaxSpeed;
	} else {
		this->_ySpeed += y;
	}
	return ;
}

void			Moving::drag( void ) {
	if (this->_xSpeed > 0.01f) {
		if (this->_xSpeed - this->_drag > 0.00001f) {
			this->_xSpeed -= this->_drag;
		} else {
			this->_xSpeed = 0.0f;
		}
	} else if (this->_xSpeed < -0.001f) {
		if (this->_xSpeed + this->_drag < -0.00001f) {
			this->_xSpeed += this->_drag;
		} else {
			this->_xSpeed = 0.0f;
		}
	} else {
		this->_xSpeed = 0.0f;
	}
	if (this->_ySpeed > 0.01f) {
		if (this->_ySpeed - this->_drag > 0.00001f) {
			this->_ySpeed -= this->_drag;
		} else {
			this->_ySpeed = 0.0f;
		}
	} else if (this->_ySpeed < -0.001f) {
		if (this->_ySpeed + this->_drag < -0.00001f) {
			this->_ySpeed += this->_drag;
		} else {
			this->_ySpeed = 0.0f;
		}
	} else {
		this->_ySpeed = 0.0f;
	}
}

// Default movement behavior
void		Moving::movement( void ) {
	this->modPos(this->_xSpeed, this->_ySpeed);
	this->drag();
	return ;
}
