/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:38 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 19:10:38 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <mlx.h>
#include <stdlib.h>

#define WINDOW_TITLE "Cub3D"
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 720

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_texture
{
	t_image	image;
	int		width;
	int		height;
}	t_texture;

typedef struct s_renderer
{
	void		*mlx;
	void		*win;
	t_image		image;
}	t_renderer;

t_renderer	init_renderer(void);
