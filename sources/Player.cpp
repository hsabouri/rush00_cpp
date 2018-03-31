#include <iostream>
#include <ncurses.h>

#include <Player.hpp>
Player::Player(void) : Movement(), _shootingSpeed(0.0f), _xShooting(0.0f), _yShooting(0.0f) {
    this->_xPos = 10.0f;
    this->_yPos = 10.0f;
}

Player::Player(const Player &src) : Movement(&src) {
    *this = src;
}

Player &Player::operator=(const Player &src) {
    return *this;
}

Player::~Player(void) {
}

void Player::shoot( void ) {
    
}

void Player::input( Window *win ) {
	int i = getch();
    if (i == 'z' || i == 's' || i == 'q' || i == 'd')
        win->updateDisplay(getIntPosX(), getIntPosY(), " ");
    if (i == 'z')
        this->x--;
    if (i == 's')
        this->x++;
    if (i == 'q')
        this->y--;
    if (i == 'd')
        this->y++;
    if (i == ' ')
        shoot();
	win->updateDisplay(getIntPosX(), getIntPosY(), "P");

}
