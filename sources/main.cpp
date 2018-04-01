/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:07:01 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:51:22 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <unistd.h>
#include "Player.hpp"
#include "Ennemy.hpp"
#include "Window.hpp"
#include "lib.hpp"

int main(void) {
	Window win = Window();
	size_t	frame = 0;
	size_t	score = 0;

	Player pl = Player(10.0f, 10.0f);

	size_t buffer_size = 500;
	size_t last_ennemy = 0;
	size_t last_bullet = 0;
	Bullet *bullets_buffer[buffer_size];
	Ennemy *ennemies_buffer[buffer_size];

	for (size_t i = 0; i < buffer_size; i++) {
		ennemies_buffer[i] = nullptr;
		bullets_buffer[i] = nullptr;
	}

	win.init();

	while (42) {
		frame++;
		std::clock_t start = std::clock();

		// Logic ///////////////////////////////////////////////////////////////
		pl.input((Bullet **)bullets_buffer, buffer_size, last_bullet);
		pl.movement();
		if ( frame % 10 == 0 ) {
			pl.shoot(bullets_buffer, buffer_size, last_bullet);
		}

		if ( frame % (getRandom(35) + 1) == 0 && last_ennemy < buffer_size) {
			ennemies_buffer[last_ennemy] = new Ennemy(199.0, getRandom(38) + 1, ((float)getRandom(10) - 10) / 20, ((float)getRandom(2) / 50) - 0.001f);
			last_ennemy++;
		}

		for (size_t i = 0; i < last_bullet; i++) { // Moving bullets
			Bullet *bul = bullets_buffer[i];
			bul->movement();
			if (bul->getStatus() == dead) {
				delete_bullet(bullets_buffer, last_bullet, i);
			}
		}
		for (size_t i = 0; i < last_ennemy; i++) { // Moving ennemies and checking collisions with bullets
			Ennemy *enn = ennemies_buffer[i];
			enn->movement();
			int touched = enn->collide(bullets_buffer, last_bullet);
			if (touched >= 0) {
				score += 1;
				delete_ennemy(ennemies_buffer, last_ennemy, i);
				delete_bullet(bullets_buffer, last_bullet, touched);
			}
			if (enn->getIntPosX() <= 2 || enn->getIntPosY() <= 2 || enn->getIntPosY() >= AbstractGameEntity::height -2 ) {
				delete_ennemy(ennemies_buffer, last_ennemy, i);
			}
		}

		int touched = pl.collide(ennemies_buffer, last_ennemy); // Checking collisions with ennemies
		if (touched >= 0) {
			win.clear();
			std::cout << std::endl;
			usleep(100000);
			std::cout << score << std::endl;
			std::exit(0);
		}

		// Update //////////////////////////////////////////////////////////////
		win.clear();
		win.updateDisplay(pl.getIntPosX(), pl.getIntPosY(), pl.getSkin());
		for (size_t i = 0; i < last_bullet; i++) {
			Bullet *bul = bullets_buffer[i];
			win.updateDisplay(bul->getIntPosX(), bul->getIntPosY(), bul->getSkin());
		}
		for (size_t i = 0; i < last_ennemy; i++) {
			Ennemy *enn = ennemies_buffer[i];
			win.updateDisplay(enn->getIntPosX(), enn->getIntPosY(), enn->getSkin());
		}
		
		win.refresh();
		std::clock_t total = (std::clock() - start) / (CLOCKS_PER_SEC / 1000000);
		usleep(10000 - total);
	}
}
