/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractGameEntity.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:44:35 by hsabouri          #+#    #+#             */
/*   Updated: 2018/03/31 12:55:39 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ABSTRACTGAMEENTITY_HPP
# define ABSTRACTGAMEENTITY_HPP

enum Status {
	alive,
	dying,
	dead
}

class AbstractGameEntity {

	public:
		static int		width;
		static int		height;

	private:
		float			_xPos;
		float			_yPos;

		unsigned char	_char;
		
		Status			_status;
}
