/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:14:48 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 09:58:35 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_mod(char *format, int i)
{
	if (format[i] == 'h')
		return (0);
	else if (format[i] == 'l')
		return (0);
	else if (format[i] == 'j')
		return (0);
	else if (format[i] == 'z')
		return (0);
	else
		return (1);
	return (1);
}

static int	check_ex(char *format, int i)
{
	if (format[i] == 'h')
		return (0);
	else if (format[i] == 'l')
		return (0);
	else
		return (1);
	return (1);
}

int			check2(char *format, int i)
{
	int ret;

	ret = 0;
	if (check_mod(format, i) == 0)
		i++;
	if (format[i] == 'h' || format[i] == 'l')
	{
		ret = check_ex(format, i);
		if (ret == 0)
			i++;
	}
	return (i);
}
