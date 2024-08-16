/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:00 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:46:28 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "utils.h"

void	move_forward(t_player *player, char **map)
{
	t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;

	player_cos = cos(player->angle) * 0.1;
	player_sin = sin(player->angle) * 0.1;
	new_pos.x = player->x + player_cos;
	new_pos.y = player->y + player_sin;
	check.x = floor(new_pos.x + player_cos * player->radius);
	check.y = floor(new_pos.y + player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}

void	move_backward(t_player *player, char **map)
{
	t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;

	player_cos = cos(player->angle) * 0.1;
	player_sin = sin(player->angle) * 0.1;
	new_pos.x = player->x - player_cos;
	new_pos.y = player->y - player_sin;
	check.x = floor(new_pos.x - player_cos * player->radius);
	check.y = floor(new_pos.y - player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}

void	move_left(t_player *player, char **map)
{
	t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;
	float	angle;

	angle = normalize_angle(player->angle + M_PI_2);
	player_cos = cos(angle) * 0.1;
	player_sin = sin(angle) * 0.1;
	new_pos.x = player->x - player_cos;
	new_pos.y = player->y - player_sin;
	check.x = floor(new_pos.x - player_cos * player->radius);
	check.y = floor(new_pos.y - player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}

void	move_right(t_player *player, char **map)
{
   t_vec2	new_pos;
	t_vec2	check;
	float	player_cos;
	float	player_sin;
	float	angle;

	angle = normalize_angle(player->angle - M_PI_2);
	player_cos = cos(angle) * 0.1;
	player_sin = sin(angle) * 0.1;
	new_pos.x = player->x - player_cos;
	new_pos.y = player->y - player_sin;
	check.x = floor(new_pos.x - player_cos * player->radius);
	check.y = floor(new_pos.y - player_sin * player->radius);
	if (map[(int)check.y][(int)player->x] == '0')
		player->y = new_pos.y;
	if (map[(int)player->y][(int)check.x] == '0')
		player->x = new_pos.x;
}

void	turn_right(t_player *player)
{
	player->angle += player->turn_speed;
	player->angle = normalize_angle(player->angle);
}

void	turn_left(t_player *player)
{
	player->angle -= player->turn_speed;
	player->angle = normalize_angle(player->angle);
}

int	keypress_hook(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->renderer.mlx);
	else if (keycode == XK_Right)
		turn_right(&game->player);
	else if (keycode == XK_Left)
		turn_left(&game->player);
	else if (keycode == XK_w)
		move_forward(&game->player, game->map);
	else if (keycode == XK_s)
		move_backward(&game->player, game->map);
	else if (keycode == XK_a)
		move_left(&game->player, game->map);
	else if (keycode == XK_d)
		move_right(&game->player, game->map);
	return (0);
}
