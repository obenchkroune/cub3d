/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:04 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 19:22:35 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"
#include "hooks.h"

t_renderer	init_renderer(void)
{
	t_renderer	r;

	r.mlx = mlx_init();
	if (!r.mlx)
		ft_panic("could not init mlx context");
	r.win = mlx_new_window(r.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
	if (!r.win)
		ft_panic("could not init mlx window");
	r.image.img = mlx_new_image(r.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!r.image.img)
		ft_panic("could not init mlx image");
	r.image.addr = mlx_get_data_addr(r.image.img,
			&r.image.bits_per_pixel, &r.image.size_line, &r.image.endian);
	if (!r.image.addr)
		ft_panic("could not get img data address");
	return (r);
}

float	get_player_angle(char c)
{
	if (c == 'N')
		return (3 * M_PI_2);
	if (c == 'S')
		return (M_PI_2);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (M_PI);
	exit(ft_error(ERR_NO_PLAYER));
}

void	set_player_pos(char **map, t_player *p)
{
	int	x;
	int	y;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]) != NULL)
			{
				p->x = x + 0.5;
				p->y = y + 0.5;
				p->angle = get_player_angle(map[y][x]);
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	exit(ft_error(ERR_NO_PLAYER));
}

t_player	init_player(char **map)
{
	t_player	player;

	player.fov = deg_to_rad(60);
	player.half_fov = player.fov / 2.0f;
	set_player_pos(map, &player);
	player.radius = 5.0f;
	player.movement_speed = 0.1f;
	player.turn_speed = deg_to_rad(5);
	return (player);
}

void	load_textures(t_game *g)
{
	g->texture.image.img = mlx_xpm_file_to_image(g->renderer.mlx,
			"textures/wall.xpm", &g->texture.width, &g->texture.height);
	if (!g->texture.image.img)
		ft_panic("could not load texture!");
	g->texture.image.addr = mlx_get_data_addr(g->texture.image.img,
			&g->texture.image.bits_per_pixel, &g->texture.image.size_line,
			&g->texture.image.endian);
	if (!g->texture.image.img)
		ft_panic("could not get texture data addr!");
}

void	setup(t_game *game, int ac, char **av)
{
	if (ac != 2)
		exit(ft_error(CUB3D_USAGE));
	if (ft_strcmp(".cub", av[1] + ft_strlen(av[1]) - 4) != 0)
		exit(ft_error(ERR_INVALID_FILENAME));
	game->map = parse_map(av[1]);
	game->renderer = init_renderer();
	game->player = init_player(game->map);
	game->win_width = SCREEN_WIDTH;
	game->win_width_2 = SCREEN_WIDTH / 2;
	game->win_height = SCREEN_HEIGHT;
	game->win_height_2 = SCREEN_HEIGHT / 2;
	game->ray_step = game->player.fov / SCREEN_WIDTH;
	game->ray_presition = 256;
	load_textures(game);
	mlx_do_key_autorepeaton(game->renderer.mlx);
	mlx_hook(game->renderer.win, KeyPress, 1, keypress_hook, game);
	mlx_hook(game->renderer.win, DestroyNotify, 0,
		mlx_loop_end, game->renderer.mlx);
}
