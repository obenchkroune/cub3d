/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:35 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 09:06:25 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2.h"
#include <math.h>

t_vec2	new_vec2(float x, float y)
{
	return ((t_vec2){x, y});
}

t_vec2	vec2_rotate(t_vec2 v, float angle)
{
	t_vec2		res;

	res.x = v.x * cos(angle) - v.y * sin(angle);
	res.y = v.x * sin(angle) + v.y * cos(angle);
	return (res);
}

t_vec2	vec2_normalize(t_vec2 v)
{
	float	magnitude;
	t_vec2	res;

	magnitude = sqrt(v.x * v.x + v.y * v.y);
	res.x = v.x / magnitude;
	res.y = v.y / magnitude;
	return (res);
}
