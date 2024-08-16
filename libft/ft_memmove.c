/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:42:19 by yaharkat          #+#    #+#             */
/*   Updated: 2024/08/16 02:31:12 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	if (dest < src || dest > (src + n))
		ft_memcpy(dest, src, n);
	else
		while (n-- > 0)
			t_dest[n] = t_src[n];
	return (dest);
}
