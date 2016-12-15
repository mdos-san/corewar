/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   U_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 13:19:54 by jcao              #+#    #+#             */
/*   Updated: 2016/03/29 14:16:50 by jcao             ###   ########.fr       */
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

static char	*char_umaj(t_pri var, va_list pa)
{
	var.unlong = va_arg(pa, unsigned long);
	var.tmp2 = ft_itoa_ulong(var.unlong, 10);
	return (var.tmp2);
}

int			umaj_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.stock = char_umaj(var, pa);
	free(var.tmp2);
	i = 0;
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = min_pre(sub, var.stock, var);
	else
	{
		var.tmp = ft_strnew(ft_strlen(var.stock + 1));
		var.tmp = ft_strcpy(var.tmp, var.stock);
	}
	while (check_flag(sub, i) == 0)
		i++;
	var.res = min_str(sub, var.tmp, var, i);
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	free(var.tmp);
	var.res = fucking_flag(var.tmp2, var.res, var, var.sub);
	ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	free(var.tmp2);
	free(var.res);
	free(var.stock);
	return (var.ret);
}
