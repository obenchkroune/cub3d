/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:58:13 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 22:58:14 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	load_texture(t_game *g, t_texture *t, char *file_name)
{
	t->image.img = mlx_xpm_file_to_image(g->renderer.mlx,
			file_name, &t->width, &t->height);
	if (!t->image.img)
		ft_panic("could not load texture!");
	t->image.addr = mlx_get_data_addr(t->image.img,
			&t->image.bits_per_pixel, &t->image.size_line,
			&t->image.endian);
	if (!t->image.img)
		ft_panic("could not get texture data addr!");
}
