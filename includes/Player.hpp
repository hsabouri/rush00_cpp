#include <Window.hpp>
#include <Moving.hpp>

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

class Player : public Moving {
public:
    Player();
    Player(const Player &src);
    ~Player();
    Player &operator=(const Player &src);

    void movement();
    void input(Window *win);
    int getX();
    int getY();
    void shoot();

    float getXShooting(void) const;
    float getYShooting(void) const;
    float getShooting(void) const;

private:
    int x;
    int y;

    float _shootingSpeed;
    float _xShooting;
    float _yShooting;
};

#endif
