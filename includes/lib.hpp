/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 10:41:25 by hsabouri          #+#    #+#             */
/*   Updated: 2018/04/01 19:50:21 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIB_HPP
# define LIB_HPP
# include "Player.hpp"
# include "Bullet.hpp"
# include "Ennemy.hpp"
# include "Window.hpp"

void	delete_bullet( Bullet **bullets, size_t &last_bullet, size_t to_del );
void	delete_ennemy( Ennemy **ennemies, size_t &last_ennemy, size_t to_del );
size_t	getRandom( unsigned int max );

#endif
