#include <iostream>
#include <ncurses.h>
#include <Player.hpp>
#include <Moving.hpp>
#include <Bullet.hpp>
#include <Window.hpp>

Player::Player( void ) :
	Moving( 0.0f,
			0.0f,
			(char *)"P",
			-1.0f * AbstractGameEntity::mult,
			0.0f,
			10.0f * AbstractGameEntity::mult,
			0.0f)
{
	return ;
}

Player::Player( float x, float y ) :
	Moving( x,
			y,
			(char *)"P",
			-1.0f * AbstractGameEntity::mult,
			0.0f,
			10.0f * AbstractGameEntity::mult,
			0.0f)
{
	return ;
}



Player::Player(const Player &src) : Moving(src) {
    *this = src;
}

Player &Player::operator=(const Player &src) {
    return *this;
}

Player::~Player(void) {
}

void Player::moveBullet( void ) {
    if (bullet_ok == true)
        bullet->movement();
}

void Player::input( Window &win) {
    this->saveCoords(getIntPosX(), getIntPosY());
	int i = getch();
    if (i == 'z')
        setPos(getPosX() - 1.0f, getPosY());
    if (i == 's')
        setPos(getPosX() + 1.0f, getPosY());
    if (i == 'q')
        setPos(getPosX(), getPosY() - 1.0f);
    if (i == 'd')
        setPos(getPosX(), getPosY() + 1.0f);
    if (i == ' ')
    {
        if (bullet_ok == true) {
            bullet->remove_self(win);
            delete bullet;
        }
        bullet = new Bullet(this->getIntPosX(), this->getIntPosY() + 1, 0.005f);
        bullet_ok = true;
    }
}

void	Player::movement( void ) {
    this->saveCoords(getIntPosX(), getIntPosY());
	this->modPos(this->getSpeedX(), this->getSpeedY());
	return ;
}
