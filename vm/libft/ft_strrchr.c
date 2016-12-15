/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:29:00 by jcao              #+#    #+#             */
/*   Updated: 2015/12/01 11:53:12 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
