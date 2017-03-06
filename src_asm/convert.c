/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:11:33 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:37:51 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static char	*exception(char *result, int size)
{
	int i;

	i = 0;
	result = (char*)malloc(size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
	return (0);
}

char		*convert(unsigned int n, int size)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	if (n == 0)
		return (exception(result, size));
	result = (char*)malloc(size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	i = 1;
	while (n > 0 && size - i >= 0)
	{
		result[size - i] = n % 256;
		n /= 256;
		i++;
	}
	return (result);
}
