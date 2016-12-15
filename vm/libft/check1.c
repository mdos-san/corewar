/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:14:14 by jcao              #+#    #+#             */
/*   Updated: 2016/03/21 14:25:13 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_flag(char *format, int i)
{
	if (format[i] == '-')
		return (0);
	else if (format[i] == '+')
		return (0);
	else if (format[i] == ' ')
		return (0);
	else if (format[i] == '#')
		return (0);
	else if (format[i] == '0')
		return (0);
	else
		return (1);
	return (1);
}

static int	check_num(char *format, int i)
{
	if (format[i] == '1')
		return (0);
	else if (format[i] == '2')
		return (0);
	else if (format[i] == '3')
		return (0);
	else if (format[i] == '4')
		return (0);
	else if (format[i] == '5')
		return (0);
	else if (format[i] == '6')
		return (0);
	else if (format[i] == '7')
		return (0);
	else if (format[i] == '8')
		return (0);
	else if (format[i] == '9')
		return (0);
	else if (format[i] == '0')
		return (0);
	else
		return (1);
	return (1);
}

int			check1(char *format, int i)
{
	if (format[i] == '%')
		return (i);
	while (check_flag(format, i) == 0)
		i++;
	while (check_num(format, i) == 0)
		i++;
	if (format[i] == '.')
	{
		i++;
		while ((check_num(format, i) == 0))
			i++;
	}
	if (check2(format, i) == -1)
		return (-1);
	else
		i = check2(format, i);
	return (i);
}
