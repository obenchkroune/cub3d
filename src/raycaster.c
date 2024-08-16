/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:23 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 09:11:19 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include "utils.h"

float	raycasting(float angle, t_game *game, t_vec2 *data)
{
	t_vec2	ray;
	t_vec2	pos;
	float	ray_cos;
	float	ray_sin;

	pos = (t_vec2){game->player.x, game->player.y};
	ray = pos;
	ray_cos = cos(angle) / game->ray_presition;
	ray_sin = sin(angle) / game->ray_presition;
	while (game->map[(int)floor(ray.y)][(int)floor(ray.x)] == '0')
	{
		ray.x += ray_cos;
		ray.y += ray_sin;
	}
	if (data != NULL)
	{
		data->x = ray.x;
		data->y = ray.y;
	}
	return (sqrt(pow(pos.x - ray.x, 2) + pow(pos.y - ray.y, 2)));
}
