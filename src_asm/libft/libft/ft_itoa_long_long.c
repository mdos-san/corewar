/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 00:49:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/08 00:56:07 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

static void	get_nb_char(long long n, int *size)
{
	while (n > 0)
	{
		n /= 10;
		*size = *size + 1;
	}
}

static char	*exception(long long n, char *result)
{
	if (n == 0)
	{
		result = (char*)malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = 0;
		return (result);
	}
	if (n == -9223372036854775807 - 1)
	{
		result = (char*)malloc(20);
		if (!result)
			return (NULL);
		result = ft_strcpy(result, "-9223372036854775808");
		return (result);
	}
	return (0);
}

static void	if_n_negative(long long *n, int *is_negative, int *size)
{
	if (*n < 0)
	{
		*n = *n * -1;
		(*is_negative)++;
		(*size)++;
	}
}

char		*ft_itoa_long_long(long long n)
{
	int		i;
	int		is_negative;
	int		size;
	char	*result;

	i = 1;
	is_negative = 0;
	size = 0;
	result = NULL;
	if (n == 0 || n == -9223372036854775807 - 1)
		return (exception(n, result));
	if_n_negative(&n, &is_negative, &size);
	get_nb_char(n, &size);
	result = (char*)malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = 0;
	while (n > 0)
	{
		result[size - i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	result[0] = (is_negative == 1) ? '-' : result[0];
	return (result);
}
