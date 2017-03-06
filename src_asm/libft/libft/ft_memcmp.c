/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 12:01:12 by ajubert           #+#    #+#             */
/*   Updated: 2015/12/15 12:01:17 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#define CAST *(unsigned char*)

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if (CAST(s1 + i) != CAST(s2 + i))
			return ((int)(CAST(s1 + i) - CAST(s2 + i)));
		i++;
	}
	return (0);
}
