#include "renderer.h"
#include "utils.h"

void	draw_ceiling(int x, float wall_height, t_renderer *renderer)
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

void	draw_wall(int x, float wall_height, t_renderer *renderer)
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

void	draw_floor(int x, float wall_height, t_renderer *renderer)
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

int	render_next_frame(t_game *game)
{
	float	distance;
	int		wall_height;
	int		x;
	float	ray_angle;
	float	ray_step;
	int		half_height;

	half_height = SCREEN_HEIGHT / 2;
	ray_angle = game->player.angle - game->player.half_fov;
	ray_step = game->player.fov / SCREEN_WIDTH;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		distance = raycasting(ray_angle, game->player.pos, game->map);
		// distance *= cos(ray_angle - game->player.angle);
		wall_height = half_height / distance;
		draw_ceiling(x, wall_height, &game->renderer);
		draw_wall(x, wall_height, &game->renderer);
		draw_floor(x, wall_height, &game->renderer);
		ray_angle += ray_step;
		x++;
	}
	mlx_put_image_to_window(game->renderer.mlx, game->renderer.win, game->renderer.image.img, 0, 0);
	return (0);
}

void	render(t_game *game)
{
	mlx_loop_hook(game->renderer.mlx, render_next_frame, game);
	mlx_loop(game->renderer.mlx);
	cleanup(game);
}
