/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:50 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 19:46:17 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "cub3d.h"

void	ft_free_matrix(char **mat)
{
	size_t	i;

	i = 0;
	while (mat && mat[i])
		free(mat[i++]);
	free(mat);
}

void	cleanup(t_game *game)
{
	mlx_destroy_image(game->renderer.mlx, game->renderer.image.img);
	mlx_destroy_image(game->renderer.mlx, game->texture.image.img);
	mlx_destroy_window(game->renderer.mlx, game->renderer.win);
	mlx_destroy_display(game->renderer.mlx);
	free(game->renderer.mlx);
	ft_free_matrix(game->map);
}
