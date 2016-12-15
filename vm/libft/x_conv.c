/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:51:33 by jcao              #+#    #+#             */
/*   Updated: 2016/04/08 11:41:41 by jcao             ###   ########.fr       */
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

static char	*char_x3(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'l')
	{
		if (sub[i - 2] == 'l')
		{
			var.unlonglong = va_arg(pa, unsigned long long);
			var.tmp2 = ft_itoa_ulong(var.unlonglong, 16);
			return (var.tmp2);
		}
		else
		{
			var.unlong = va_arg(pa, unsigned long);
			var.tmp2 = ft_itoa_ulong(var.unlong, 16);
			return (var.tmp2);
		}
	}
	return (var.tmp2);
}

static char	*char_x2(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'h')
	{
		if (sub[i - 2] == 'h')
		{
			var.char_uconv = va_arg(pa, unsigned int);
			var.tmp2 = ft_itoa_base(var.char_uconv, 16);
			return (var.tmp2);
		}
		else
		{
			var.short_unconv = va_arg(pa, unsigned int);
			var.tmp2 = ft_itoa_base(var.short_unconv, 16);
			return (var.tmp2);
		}
	}
	else
		var.tmp2 = char_x3(sub, var, pa, i);
	return (var.tmp2);
}

static char	*char_x(char *sub, t_pri var, va_list pa)
{
	int i;

	i = ft_strlen(sub) - 1;
	if (sub[i - 1] == 'z')
	{
		var.size_conv = va_arg(pa, size_t);
		var.tmp2 = ft_itoa_ulong(var.size_conv, 16);
	}
	else if (sub[i - 1] == 'j')
	{
		var.uintmax_conv = va_arg(pa, uintmax_t);
		var.tmp2 = ft_itoa_ulong(var.uintmax_conv, 16);
	}
	else if (sub[i - 1] == 'h' || sub[i - 1] == 'l')
		var.tmp2 = char_x2(sub, var, pa, i);
	else
	{
		var.uniconv = va_arg(pa, unsigned int);
		var.tmp2 = ft_itoa_base(var.uniconv, 16);
	}
	return (var.tmp2);
}

int			x_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.stock = char_x(sub, var, pa);
	i = 0;
	free(var.tmp2);
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = min_pre(sub, var.stock, var);
	else
		var.tmp = ft_strdup(var.stock);
	while (check_flag(sub, i) == 0)
		i++;
	var.res = min_str(sub, var.tmp, var, i);
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	if ((sub[0] == '.' && ft_strlen(var.tmp) == 0) ||
	(var.tmp2[0] == '#' && sub[1] == '.' && ft_strlen(var.tmp) == 0))
		var.ret--;
	free(var.tmp);
	var.res = fucking_flag(var.tmp2, var.res, var, var.sub);
	ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	free(var.tmp2);
	free(var.res);
	free(var.stock);
	return (var.ret);
}
