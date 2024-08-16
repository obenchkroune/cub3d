/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:23 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 22:14:07 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include "utils.h"

void	init_ray_data(t_ray_data *data)
{
	data->map_x = (int)data->pos.x;
	data->map_y = (int)data->pos.y;
	data->delta_dist.x = fabs(1 / data->ray.x);
	data->delta_dist.y = fabs(1 / data->ray.y);
	if (data->ray.x < 0)
	{
		data->step.x = -1;
		data->side_dist.x = (data->pos.x - data->map_x) * data->delta_dist.x;
	}
	else
	{
		data->step.x = 1;
		data->side_dist.x = (data->map_x + 1.0 - data->pos.x) * data->delta_dist.x;
	}
	if (data->ray.y < 0)
	{
		data->step.y = -1;
		data->side_dist.y = (data->pos.y - data->map_y) * data->delta_dist.y;
	}
	else
	{
		data->step.y = 1;
		data->side_dist.y = (data->map_y + 1.0 - data->pos.y) * data->delta_dist.y;
	}
}

float	get_distance(t_ray_data *data, t_vec2 *hit_pos)
{
	float	distance;
	
	if (data->side == 0)
		distance = (data->map_x - data->pos.x + (1 - data->step.x) / 2) / data->ray.x;
	else
		distance = (data->map_y - data->pos.y + (1 - data->step.y) / 2) / data->ray.y;
	if (hit_pos != NULL)
	{
	    hit_pos->x = data->side_dist.x;
	    hit_pos->y = data->side_dist.y;
	}
	return (distance);
}

float	raycasting(float angle, t_game *game, t_vec2 *hit_pos)
{
	t_ray_data	data;

	data.pos = (t_vec2){game->player.x, game->player.y};
	data.ray = (t_vec2){cos(angle), sin(angle)};
	init_ray_data(&data);
	while (game->map[data.map_y][data.map_x] == '0')
	{
		if (data.side_dist.x < data.side_dist.y)
		{
			data.side_dist.x += data.delta_dist.x;
			data.map_x += data.step.x;
			data.side = 0;
		}
		else
		{
			data.side_dist.y += data.delta_dist.y;
			data.map_y += data.step.y;
			data.side = 1;
		}
	}
	return (get_distance(&data, hit_pos));
}
