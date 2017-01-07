/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:39:49 by jcao              #+#    #+#             */
/*   Updated: 2015/12/02 11:38:01 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	l;

	l = 0;
	i = 0;
	k = 0;
	if (s2[k] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		l = i;
		k = 0;
		while ((s1[l] == s2[k] && s2[k] != '\0' && l < n))
		{
			l++;
			k++;
			if (s2[k] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
