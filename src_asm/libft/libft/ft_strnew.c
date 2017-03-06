/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:36:02 by ajubert           #+#    #+#             */
/*   Updated: 2016/01/12 14:36:05 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char*)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	*(result + size) = 0;
	while (i < size)
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}
