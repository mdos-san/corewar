/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:55:08 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 13:51:52 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*sub_zero(char *format, int init, int i, char *sub)
{
	if (sub != NULL)
		free(sub);
	sub = ft_strsub(format, init, i - init + 1);
	return (sub);
}

static int	no_str(char *sub)
{
	if (ft_strlen(sub) == 0)
	{
		free(sub);
		return (1);
	}
	else
		return (0);
}

int			ft_printf(char *format, ...)
{
	t_pri	var;
	va_list	pa;

	if (format == NULL)
		return (-1);
	ft_bzero(&var, sizeof(t_pri));
	va_start(pa, format);
	while (format[var.i] != '\0')
	{
		if (format[var.i] == '%')
		{
			var.init = var.i + 1;
			var.i = check1(format, var.i + 1);
			var.sub = sub_zero(format, var.init, var.i, var.sub);
			if (no_str(var.sub) == 1)
				return (var.ret);
			var.ret = display(var.sub, var, pa) - ft_strlen(var.sub);
		}
		else
			ft_putchar(format[var.i]);
		var.i++;
	}
	va_end(pa);
	free(var.sub);
	return (var.ret + var.i);
}
