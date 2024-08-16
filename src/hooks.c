#include "hooks.h"
#include "utils.h"

int	keypress_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->renderer.mlx);
	else if (keycode == XK_Right)
		game->player.angle += deg_to_rad(5);
	else if (keycode == XK_Left)
		game->player.angle -= deg_to_rad(5);
	return (0);
}
