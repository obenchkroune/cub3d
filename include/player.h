#pragma once

#include "vec2.h"

typedef struct s_player
{
	t_vec2	pos;
	float	angle;
	float	fov;
	float	half_fov;
}	t_player;

t_player	init_player(char **map);
