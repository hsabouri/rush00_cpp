/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:32:12 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:50:02 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Bullet.hpp"
#include "Ennemy.hpp"
#include "Window.hpp"

void	delete_bullet( Bullet **bullets, size_t &last_bullet, size_t to_del ) {
	delete bullets[to_del];
	--last_bullet;
	if (last_bullet != to_del) {
		bullets[to_del] = bullets[last_bullet];
		bullets[last_bullet] = NULL;
	}
}

void	delete_ennemy( Ennemy **ennemies, size_t &last_ennemy, size_t to_del ) {
	delete ennemies[to_del];
	--last_ennemy;
	if (last_ennemy != to_del) {
		ennemies[to_del] = ennemies[last_ennemy];
		ennemies[last_ennemy] = NULL;
	}
}

size_t getRandom( unsigned int max ) {
	size_t res = (size_t)(
			((float)(std::rand() - 1) /
			 (float)(RAND_MAX)) * (max)
			);

	return res;
}
