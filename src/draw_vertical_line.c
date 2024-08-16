/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:53 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:22:54 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_verical_line(t_image *image, t_vec2 start, t_vec2 end, int color)
{
	if (start.x != end.x || start.y >= SCREEN_HEIGHT)
		return ;
	if (start.y < 0)
		start.y = 0;
	if (end.y >= SCREEN_HEIGHT)
		end.y = SCREEN_HEIGHT - 1;
	while (start.y <= end.y)
	{
		plot_pixel(image, start.x, start.y, color);
		start.y++;
	}
}
