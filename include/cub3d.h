/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 02:43:12 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 03:10:25 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "renderer.h"
#include "vec2.h"
#include "camera.h"
#include <X11/X.h>
#include "libft.h"
#include "colors.h"

#define CUB3D_USAGE "usage ./cub3d [/path/to/map.cub]!"
#define ERR_INVALID_FILENAME "The map file must be ending with .cub!"
#define ERR_NO_PLAYER "No player found!"

typedef struct s_game
{
	t_renderer	r;
	t_camera	c;
	char		**map;
}	t_game;

char	**parse_map(const char *file_name);
void	setup(t_game *game, int ac, char **av);
void	render(t_game *game);
