/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:02:20 by ajubert           #+#    #+#             */
/*   Updated: 2015/12/15 12:02:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	return (dst);
}
