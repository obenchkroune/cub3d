/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 08:48:27 by obenchkr          #+#    #+#             */
/*   Updated: 2024/08/22 08:49:11 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_panic(const char *msg)
{
	perror(msg);
	exit(1);
}

int	ft_error(const char *msg)
{
	ft_putstr_fd(ANSI_COLOR_RED, STDERR_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putstr_fd(ANSI_COLOR_RESET, STDERR_FILENO);
	ft_putendl_fd((char *)msg, STDERR_FILENO);
	return (1);
}
