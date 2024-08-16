/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:35 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:42:55 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vec2.h"

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	float	fov;
	float	half_fov;
	float	radius;
	float	turn_speed;
	float	movement_speed;
}	t_player;

t_player	init_player(char **map);
