/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:02:07 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 23:07:12 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_texture	*get_texture(t_game *g, t_ray *data)
{
	if (data->side == 0)
	{
		if (data->dir.x > 0)
			return (&g->west_texture);
		else
			return (&g->east_texture);
	}
	else
	{
		if (data->dir.y > 0)
			return (&g->north_texture);
		else
			return (&g->south_texture);
	}
}

void	draw_ceiling(t_renderer *renderer, int x, float wall_height)
{
	int	start;
	int	end;
	int	half_height;

	half_height = SCREEN_HEIGHT / 2;
	start = 0;
	end = half_height - wall_height;
	draw_verical_line(&renderer->image,
		(t_vec2){x, start},
		(t_vec2){x, end},
		ft_rgb(0, 0, 0));
}

void	draw_wall(t_game *g, int x, float wall_height, t_ray *data)
{
	float		texture_x;
	int			i;
	int			start;
	int			end;
	t_texture	*t;

	t = get_texture(g, data);
	texture_x = (int)(fmodf(data->hit.x + data->hit.y, 1.0f) * t->width);
	start = g->win_height_2 - wall_height;
	end = (int)(start + 2.0f * wall_height);
	if (end >= g->win_height)
		end = g->win_height - 1;
	i = start;
	if (i < 0)
		i = 0;
	while (i < end)
	{
		plot_pixel(&g->renderer.image, x, i, get_pixel_color(&t->image,
				(int)texture_x, (int)(((i - start) / (2.0f * wall_height))
					* t->height) % t->height));
		i++;
	}
}

void	draw_floor(t_renderer *renderer, int x, float wall_height)
{
	int		start;
	int		end;
	int		half_height;

	half_height = SCREEN_HEIGHT / 2;
	start = half_height + wall_height;
	end = SCREEN_HEIGHT - 1;
	draw_verical_line(&renderer->image,
		(t_vec2){x, start},
		(t_vec2){x, end},
		ft_rgb(100, 100, 100));
}
