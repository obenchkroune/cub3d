/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:42 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:37:20 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cub3d.h"

void	ft_panic(const char *msg);
int		ft_error(const char *msg);
int		ft_rgb(int r, int g, int b);
float	deg_to_rad(float deg);
float	normalize_angle(float angle);
void	cleanup(t_game *g);
void	ft_free_matrix(char **mat);
void	plot_pixel(t_image *img, int x, int y, int color);
void	draw_verical_line(t_image *image, t_vec2 start, t_vec2 end, int color);
