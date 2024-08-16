#pragma once

#include "vec2.h"

typedef struct s_camera
{
	t_vec2	pos;
	t_vec2	dir;
	float	fov;
	float	half_fov;
}	t_camera;

t_camera	init_camera(char **map);
