/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 18:31:58 by jcao              #+#    #+#             */
/*   Updated: 2016/10/24 18:34:53 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		hexa(const char *str, int res, int str_base, int i)
{
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 &&
	str[i] <= 54 + str_base) || (str[i] >= 97 && str[i] <= 86 + str_base))
	{
		while (str[i] >= 65 && str[i] <= 54 + str_base)
		{
			res = res * str_base + str[i] - 55;
			i++;
		}
		while (str[i] >= 97 && str[i] <= 86 + str_base)
		{
			res = res * str_base + str[i] - 87;
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			res = res * str_base + str[i] - '0';
			i++;
		}
	}
	return (res);
}

unsigned int			ft_atoi_base(const char *str, int str_base)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	if (str_base <= 0 && str_base > 16)
		return (0);
	if (str[i] == '\t' || str[i] == '\v' || str[i] == ' ' || str[i] == '\n' ||
		str[i] == '\b' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		return (0);
	if (str_base > 10)
		res = hexa(str, res, str_base, i);
	else
	{
		while (str[i] >= 48 && str[i] <= 47 + str_base)
		{
			res = res * str_base + str[i] - '0';
			i++;
		}
	}
	return (res);
}
