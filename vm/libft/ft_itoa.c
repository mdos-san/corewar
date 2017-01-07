/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:42:29 by jcao              #+#    #+#             */
/*   Updated: 2016/11/28 14:30:36 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*tab_res(char *tmp, char *res, unsigned long long k)
{
	long long	i;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	i--;
	free(res);
	if (k != 1)
		res = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 1);
	else
	{
		res = (char *)malloc(sizeof(char) * ft_strlen(tmp) + 2);
		res[0] = '-';
	}
	while (i >= 0)
	{
		res[k] = tmp[i];
		k++;
		i--;
	}
	res[k] = '\0';
	return (res);
}

static char	*function(long long val)
{
	unsigned long long	i;
	unsigned long long	l;
	char				*tmp;

	i = 0;
	l = 0;
	if (!(tmp = ft_strnew(40)))
		return (NULL);
	while (val >= 10)
	{
		l = val;
		l = val % 10 + '0';
		tmp[i] = l;
		i++;
		val = val / 10;
	}
	if (val < 10)
		tmp[i] = val % 10 + '0';
	return (tmp);
}

char		*ft_itoa(long long n)
{
	char				*tmp;
	char				*res;
	long long			value;
	unsigned long long	k;

	if (!(res = ft_strnew(2)))
		return (NULL);
	k = 0;
	value = 0;
	value = n;
	if (n < 0)
	{
		value = -n;
		if (value < 0)
			return (ft_strdup("-9223372036854775808"));
		res[0] = '-';
		k = 1;
	}
	tmp = function(value);
	res = tab_res(tmp, res, k);
	free(tmp);
	return (res);
}
