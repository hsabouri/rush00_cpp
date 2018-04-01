#include <Moving.hpp>
#include <Bullet.hpp>
#include <Window.hpp>

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

class Player : public Moving {
public:
    Player( void );
    Player( float x, float y );
    Player(const Player &src);
    ~Player();
    Player &operator=(const Player &src);

    void input(Window &win);
    float getXShooting(void) const;
    float getYShooting(void) const;
    float getShooting(void) const;

    void moveBullet( void );

    void	movement( void );

    Bullet *bullet;
    bool bullet_ok;
};

#endif
