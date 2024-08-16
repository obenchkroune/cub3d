/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:32 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:52:44 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"
#include <X11/keysym.h>

int		keypress_hook(int keycode, t_game *g);
void	move_forward(t_player *player, char **map);
void	move_backward(t_player *player, char **map);
void	move_left(t_player *player, char **map);
void	move_right(t_player *player, char **map);
