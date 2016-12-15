/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:28:08 by jcao              #+#    #+#             */
/*   Updated: 2015/12/05 16:06:06 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char*)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
