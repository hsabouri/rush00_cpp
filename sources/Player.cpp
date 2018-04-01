/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <jde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 09:57:23 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 22:06:41 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <ncurses.h>
#include "Player.hpp"
#include "Moving.hpp"
#include "Bullet.hpp"
#include "Window.hpp"
#include "lib.hpp"

Player::Player( void ) :
	Moving( 0.0f,
			0.0f,
			(char *)"]=0",
			0.0f * AbstractGameEntity::mult,
			0.0f,
			0.3f * AbstractGameEntity::mult,
			0.2f * AbstractGameEntity::mult,
			0.01f)
{
	return ;
}

Player::Player( float x, float y ) :
	Moving( x,
			y,
			(char *)"]=0",
			0.0f * AbstractGameEntity::mult,
			0.0f,
			0.3f * AbstractGameEntity::mult,
			0.2f * AbstractGameEntity::mult,
			0.01f)
{
	return ;
}

Player::Player(const Player &src) : Moving(src) {
    *this = src;
}

Player &Player::operator=(const Player &src) {
	this->cooldown = src.cooldown;
    return *this;
}

Player::~Player(void) {
}

void Player::input( Bullet **bullets, size_t buffer_size, size_t &last_bullet ) {
    this->saveCoords(getIntPosX(), getIntPosY());
	char i = getch();
    if (i == 'w') {
       	modSpeeds(0.0f, -0.5f);
	}
	else if (i == 's') {
       	modSpeeds(0.0f, 0.5f);
	}
	else if (i == 'a') {
		modSpeeds(-0.5f, 0.0f);
	}
	else if (i == 'd') {
		modSpeeds(0.5f, 0.0f);
	}
	else if (i == 'e') {
		modSpeeds(0.5f, -0.5f);
	}
	else if (i == 'q') {
		modSpeeds(-0.5f, -0.5f);
	}
	else if (i == 'c') {
		modSpeeds(0.5f, 0.5f);
	}
	else if (i == 'z') {
		modSpeeds(-0.5f, 0.5f);
	}
	else if (i == 27) {
		std::exit(0);
	}
	else if (i == ' ') {
		this->shoot_bomb(bullets, buffer_size, last_bullet);
	}
}

void	Player::shoot(Bullet **buffer, size_t size, size_t & last_bullet) {
	if (last_bullet >= size)
		delete_bullet(buffer, last_bullet, 0);
	buffer[last_bullet] = new Bullet(getPosX() + 3.0f, getPosY(), 0.0f);
	last_bullet++;
}

void	Player::shoot_bomb(Bullet **buffer, size_t size, size_t & last_bullet) {
	for (int i = 0; i < 10; i++) {
		float ySpeed = ((float)getRandom(10) - 5) / 15;

		if (last_bullet >= size) {
			delete_bullet(buffer, last_bullet, i);
		}
		buffer[last_bullet] = new Bullet(getPosX() + 3.0f, getPosY(), 0.5f - std::abs(ySpeed), ySpeed, (char *)"*", 0.01f);
		last_bullet++;
	}
}

int 	Player::collide(Ennemy **ennemies, size_t size) {
	int touched = -1;
	int this_pos_x = this->getIntPosX();
	int this_pos_y = this->getIntPosY();

	for (size_t i = 0; i < size; i++) {
		int ennemy_pos_x = ennemies[i]->getIntPosX();
		int ennemy_pos_y = ennemies[i]->getIntPosY();

		if (ennemies[i]->getStatus() == alive && this_pos_y == ennemy_pos_y && this_pos_x == ennemy_pos_x) {
			this->setStatus(dying);
			touched = i;
			break;
		}
	}
	return touched;
	// returns -1 or the id of the touched element, the element is destroyed and setted to null
}

void	Player::movement( void ) {
	this->modPos(this->getSpeedX(), this->getSpeedY());
	this->drag();
	return ;
}
