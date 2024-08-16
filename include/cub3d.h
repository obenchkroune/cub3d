/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:43:12 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:55:15 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "renderer.h"
#include "vec2.h"
#include "player.h"
#include <X11/X.h>
#include "libft.h"
#include "colors.h"

#define TWO_PI 6.283185307179586232

#define CUB3D_USAGE "usage ./cub3d [/path/to/map.cub]!"
#define ERR_INVALID_FILENAME "The map file must be ending with .cub!"
#define ERR_NO_PLAYER "No player found!"

typedef struct s_game
{
	t_renderer	renderer;
	t_player	player;
	char		**map;
	int			win_width;
	int			win_height;
	int			win_width_2;
	int			win_height_2;
}	t_game;

char	**parse_map(const char *file_name);
void	setup(t_game *game, int ac, char **av);
void	render(t_game *game);
float	raycasting(float angle, t_vec2 pos, char **map);
