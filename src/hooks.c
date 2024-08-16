#include "hooks.h"

int	keypress_hook(int keycode, t_game *g)
{
	if (keycode == XK_Escape)
		mlx_loop_end(g->r.mlx);
	return (0);
}
