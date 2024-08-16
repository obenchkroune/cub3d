#include "cub3d.h"
#include "utils.h"
#include "hooks.h"

t_renderer	init_renderer(int win_width, int win_height, char *title)
{
	t_renderer	r;

	r.win_width = win_width;
	r.half_win_width = win_width / 2;
	r.win_height = win_height;
	r.half_win_height = win_height / 2;
	r.mlx = mlx_init();
	if (!r.mlx)
		ft_panic("could not init mlx context");
	r.win = mlx_new_window(r.mlx, win_width, win_height, title);
	if (!r.win)
		ft_panic("could not init mlx window");
	r.img = mlx_new_image(r.mlx, win_width, win_height);
	if (!r.img)
		ft_panic("could not init mlx image");
	r.addr = mlx_get_data_addr(r.img, &r.bits_per_pixel, &r.size_line, &r.endian);
	if (!r.addr)
		ft_panic("could not get img data address");
	return (r);
}

t_camera	init_camera(char **map)
{
	t_camera	c;
	int			x;
	int			y;

	c.fov = deg_to_rad(60.0f);
	c.half_fov = c.fov / 2.0f;
	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]) != NULL)
			{
				c.pos = (t_vec2){x + 0.5f, y + 0.5f};
				return (c);
			}
			x++;
		}
		y++;
	}
	exit(ft_error(ERR_NO_PLAYER));
}

void	setup(t_game *game, int ac, char **av)
{
	if (ac != 2)
		exit(ft_error(CUB3D_USAGE));
	if (ft_strcmp(".cub", av[1] + ft_strlen(av[1]) - 4) != 0)
		exit(ft_error(ERR_INVALID_FILENAME));
	game->map = parse_map(av[1]);
	game->r = init_renderer(1024, 720, "Cub3D");
	game->c = init_camera(game->map);
	mlx_do_key_autorepeaton(game->r.mlx);
	mlx_hook(game->r.win, KeyPress, 1, keypress_hook, game);
	mlx_hook(game->r.win, DestroyNotify, 0, mlx_loop_end, game->r.mlx);
}
