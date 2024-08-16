/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:23:32 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/16 08:23:33 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "colors.h"

void	ft_panic(const char *msg)
{
	perror(msg);
	exit(1);
}

float	deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

int	ft_error(const char *msg)
{
	ft_putstr_fd(ANSI_COLOR_RED, STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd(ANSI_COLOR_RESET, STDERR_FILENO);
	ft_putendl_fd((char*)msg, STDERR_FILENO);
	return (1);
}
