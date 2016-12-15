/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 17:40:18 by jcao              #+#    #+#             */
/*   Updated: 2015/12/10 14:23:44 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size <= dst_size)
		return (size + src_size);
	while (src[i] != '\0' && dst_size + i < (size - 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
