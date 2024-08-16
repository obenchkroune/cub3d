#include "renderer.h"
#include <utils.h>

void	render(t_game *game)
{
	mlx_loop(game->r.mlx);
	cleanup(game);
}
