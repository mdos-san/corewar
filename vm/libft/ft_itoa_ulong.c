/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:59:06 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:03:31 by jcao             ###   ########.fr       */
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
	res = ft_strnew(ft_strlen(tmp + 1));
	while (i >= 0)
	{
		res[k] = tmp[i];
		k++;
		i--;
	}
	res[k] = '\0';
	return (res);
}

static char	*function(unsigned long long val, char *s2, unsigned int base)
{
	unsigned long long	i;
	unsigned long long	l;

	i = 0;
	l = 0;
	while (val >= base)
	{
		l = val;
		l = val % base;
		if (l < 10)
			s2[i] = l + '0';
		else
			s2[i] = l + 87;
		i++;
		val = val / base;
	}
	if (val < base)
	{
		if (val < 10)
			s2[i] = val + '0';
		else
			s2[i] = val + 87;
	}
	return (s2);
}

char		*ft_itoa_ulong(unsigned long long n, unsigned int base)
{
	char				*tmp;
	char				*res;
	unsigned long long	value;
	unsigned long long	k;

	if (!(tmp = ft_strnew(22)))
		return (NULL);
	if (!(res = ft_strnew(2)))
		return (NULL);
	k = 0;
	value = 0;
	value = n;
	tmp = function(value, tmp, base);
	res = tab_res(tmp, res, k);
	free(tmp);
	return (res);
}
