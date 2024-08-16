#pragma once

#include <mlx.h>
#include <stdlib.h>

typedef struct s_renderer
{
	int		win_width;
	int		win_height;
	int		half_win_width;
	int		half_win_height;
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_renderer;

t_renderer	init_renderer(int win_width, int win_height, char *title);
