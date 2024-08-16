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
	mlx_destroy_image(game->r.mlx, game->r.img);
	mlx_destroy_window(game->r.mlx, game->r.win);
	mlx_destroy_display(game->r.mlx);
	free(game->r.mlx);
	ft_free_matrix(game->map);
}
