#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cub3d.h"

void	ft_panic(const char *msg);
int		ft_error(const char *msg);
float	deg_to_rad(float deg);
void	cleanup(t_game *g);
void	ft_free_matrix(char **mat);
