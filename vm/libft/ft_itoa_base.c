/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:42:29 by jcao              #+#    #+#             */
/*   Updated: 2016/12/03 17:04:55 by jcao             ###   ########.fr       */
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

static char	*function(long long val, char *s2, unsigned int base)
{
	long long	i;
	long long	l;

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

char		*ft_itoa_base(long long int n, unsigned int base)
{
	char				*tmp;
	char				*res;
	long long			value;
	unsigned long long	k;

	if (!(tmp = ft_strnew(22)))
		return (NULL);
	if (!(res = ft_strnew(2)))
		return (NULL);
	k = 0;
	value = 0;
	value = n;
	if (n < 0)
	{
		value = -n;
		if (value < 0 && base == 8)
			return (ft_strdup("1000000000000000000000"));
		res[0] = '-';
		k = 1;
	}
	tmp = function(value, tmp, base);
	res = tab_res(tmp, res, k);
	free(tmp);
	return (res);
}
