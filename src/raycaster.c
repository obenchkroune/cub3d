/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:23 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:23:23 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include "utils.h"

float	raycasting(float angle, t_vec2 pos, char **map)
{
	t_vec2	ray;
	float	ray_cos;
	float	ray_sin;

	ray = pos;
	ray_cos = cos(angle) / 128;
	ray_sin = sin(angle) / 128;
	while (map[(int)floor(ray.y)][(int)floor(ray.x)] == '0')
	{
		ray.x += ray_cos;
		ray.y += ray_sin;
	}
	return (sqrt(pow(pos.x - ray.x, 2) + pow(pos.y - ray.y, 2)));
}
