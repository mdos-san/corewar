/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:00:25 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:02:59 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 0;
	while (str[i] == 32 || str[i] == '\v' || str[i] == '\t' || str[i] == '\f' ||
		str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-result);
	return (result);
}
