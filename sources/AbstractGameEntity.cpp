/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:40:08 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 18:25:23 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AbstractGameEntity.hpp>

// Static attributes

int		AbstractGameEntity::width = 200;
int		AbstractGameEntity::height = 40;
float	AbstractGameEntity::mult = 1;

// Coplien

AbstractGameEntity::AbstractGameEntity( void ) : 
	_xPos(0), _yPos(0),
	_status(alive),
	_skin((char *)".")
{
	return ;
}

AbstractGameEntity::~AbstractGameEntity( void ) {
	return ;
}

AbstractGameEntity::AbstractGameEntity( float x, float y, char *skin ) :
	_xPos(x), _yPos(y),
	_status(alive),
	_skin(skin)
{
	return ;
}

AbstractGameEntity::AbstractGameEntity( AbstractGameEntity const & src ) :
	_xPos(src.getPosX()), _yPos(src.getPosY()),
	_status(src.getStatus()),
	_skin(src.getSkin())
{
	return ;
}

AbstractGameEntity & AbstractGameEntity::operator=( AbstractGameEntity const & rhs ) {
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_skin = rhs._skin;
	this->_status = rhs._status;
	return *this;
}

// Member functions

void			AbstractGameEntity::myscroll( float amount ) {
	(void)amount;
	return ;
}

int				AbstractGameEntity::getIntPosX( void ) const {
	return static_cast<int>(this->_xPos);
}

int				AbstractGameEntity::getIntPosY( void ) const {
	return static_cast<int>(this->_yPos);
}

float			AbstractGameEntity::getPosX( void ) const {
	return (this->_xPos);
}

float			AbstractGameEntity::getPosY( void ) const {
	return (this->_yPos);
}

Status			AbstractGameEntity::getStatus( void ) const {
	return this->_status;
}

char	*AbstractGameEntity::getSkin( void ) const {
	return this->_skin;
}

void			AbstractGameEntity::setPos( float x, float y ) {
	this->_xPos = x;
	this->_yPos = y;
	return ;
}

void			AbstractGameEntity::modPos( float x, float y ) {
	if (this->_xPos + x > 2 || x > 0.0f) {
		this->_xPos += x;
	} else if (x < 0.0f) {
		this->_xPos = 2;
	}
	if (this->_xPos + x < AbstractGameEntity::width - 2 || x < 0.0f) {
		this->_xPos += x;
	} else if (x > 0.0f) {
		this->_xPos = AbstractGameEntity::width - 2;
	}
	if (this->_yPos + y > 2 || y > 0.0f) {
		this->_yPos += y;
	} else if (y < 0.0f) {
		this->_yPos = 2;
	}
	if (this->_yPos + y <= AbstractGameEntity::height - 2 || y < 0.0f) {
		this->_yPos += y;
	} else if (y > 0.0f) {
		this->_yPos = AbstractGameEntity::height - 2;
	}

	return ;
}

void			AbstractGameEntity::setSkin( char *skin ) {
	this->_skin = skin;
	return ;
}

void			AbstractGameEntity::setStatus( Status newStatus ) {
	this->_status = newStatus;
	return ;
}

void			AbstractGameEntity::saveCoords(int x, int y) {
	this->oldX = x;
	this->oldY = y;
}

int				AbstractGameEntity::getOldX( void ) {
	return this->oldX;
}
int				AbstractGameEntity::getOldY( void ) {
	return this->oldY;
}

