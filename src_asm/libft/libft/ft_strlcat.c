/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:32:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:32:39 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	end_str;
	size_t	len_dst;

	i = 0;
	i2 = 0;
	end_str = 0;
	len_dst = 0;
	if (!dst || !src)
		return (0);
	end_str = size - ft_strlen(dst) - 1;
	len_dst = ft_strlen(dst);
	if ((int)end_str < 0)
		return (size + ft_strlen(src));
	while (*(dst + i) != '\0')
		i++;
	while ((int)i2 < (int)end_str)
	{
		dst[i] = src[i2];
		i++;
		i2++;
	}
	dst[i] = 0;
	return (len_dst + ft_strlen(src));
}
