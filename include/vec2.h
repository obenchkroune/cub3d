/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:22:46 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 09:06:25 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

t_vec2	vec2_rotate(t_vec2 v, float angle);
t_vec2	vec2_normalize(t_vec2 v);
t_vec2	new_vec2(float x, float y);
