/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 11:56:32 by ajubert           #+#    #+#             */
/*   Updated: 2015/12/15 11:56:36 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = 0;
	if ((int)size <= 0)
		return (NULL);
	mem = (char *)malloc(size + 1);
	if (mem == NULL)
		return (NULL);
	*(char*)(mem + size) = '\0';
	while (i < size)
	{
		*(char*)(mem + i) = '\0';
		i++;
	}
	return (mem);
}
