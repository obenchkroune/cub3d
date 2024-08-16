/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:19:23 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 09:13:44 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "utils.h"

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

void	draw_wall(t_renderer *renderer, int x, float wall_height)
{
	int		start;
	int		end;
	int		half_height;

	half_height = SCREEN_HEIGHT / 2;
	start = half_height - wall_height;
	end = half_height + wall_height;
	draw_verical_line(&renderer->image,
		(t_vec2){x, start},
		(t_vec2){x, end},
		ft_rgb(0, 10, 150));
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

int	render_next_frame(t_game *g)
{
	float	distance;
	int		wall_height;
	int		x;
	float	ray_angle;
	t_vec2	ray;

	ray_angle = g->player.angle - g->player.half_fov;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		distance = raycasting(ray_angle, g, &ray);
		distance *= cos(ray_angle - g->player.angle);
		wall_height = floor(g->win_height_2 / distance);
		draw_ceiling(&g->renderer, x, wall_height);
		draw_wall(&g->renderer, x, wall_height); // TODO: render a texture instad of a solid color
		draw_floor(&g->renderer, x, wall_height);
		ray_angle += g->ray_step;
		x++;
	}
	mlx_put_image_to_window(g->renderer.mlx, g->renderer.win,
		g->renderer.image.img, 0, 0);
	return (0);
}

void	render(t_game *game)
{
	mlx_loop_hook(game->renderer.mlx, render_next_frame, game);
	mlx_loop(game->renderer.mlx);
	cleanup(game);
}
