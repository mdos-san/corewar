/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:38:05 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:38:08 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (!s)
		return (NULL);
	while (i < len)
	{
		*(result + i) = *(s + start + i);
		i++;
	}
	*(result + i) = 0;
	return (result);
}
