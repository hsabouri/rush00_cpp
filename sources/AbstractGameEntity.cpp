/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 13:40:08 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 15:14:39 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractGameEntity.hpp"

// Static attributes

int		AbstractGameEntity::width = 0;
int		AbstractGameEntity::height = 0;
float	AbstractGameEntity::mult = 1;

// Coplien

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

void			AbstractGameEntity::scroll( float amount ) {
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

unsigned char	AbstractGameEntity::getSkin( void ) const {
	return this->_skin;
}

void			AbstractGameEntity::setPos( float x, float y ) {
	this->_xPos = x;
	this->_yPos = y;
	return ;
}

void			AbstractGameEntity::modPos( float x, float y ) {
	if (this->_xPos + x <= AbstractGameEntity::width && this->_xPos + x >= 0) {
		this->_xPos += x;
	}
	if (this->_yPos + y <= AbstractGameEntity::height && this->_yPos + y >= 0) {
		this->_yPos += y;
	}
	return ;
}

void			AbstractGameEntity::setSkin( unsigned char skin ) {
	this->_skin = skin;
	return ;
}

void			AbstractGameEntity::setStatus( Status newStatus ) {
	this->_status = newStatus;
	return ;
}
