/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:36:18 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:36:22 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		i2;
	size_t		len_s2;

	i = 0;
	i2 = 0;
	len_s2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*(s1 + i) != '\0' && i < n)
	{
		while (*(s1 + i + i2) == *(s2 + i2) && i2 < len_s2 && i + i2 < n)
			i2++;
		if (i2 == len_s2)
			return ((char *)(s1 + i));
		else
			i2 = 0;
		i++;
	}
	return (NULL);
}
