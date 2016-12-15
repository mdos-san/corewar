/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:46:44 by jcao              #+#    #+#             */
/*   Updated: 2016/03/29 14:21:00 by jcao             ###   ########.fr       */
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

static char	*char_u3(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'l')
	{
		if (sub[i - 2] == 'l')
		{
			var.unlonglong = va_arg(pa, unsigned long long);
			var.tmp2 = ft_itoa_ulong(var.unlonglong, 10);
			return (var.tmp2);
		}
		else
		{
			var.unlong = va_arg(pa, unsigned long);
			var.tmp2 = ft_itoa_ulong(var.unlong, 10);
			return (var.tmp2);
		}
	}
	return (var.tmp2);
}

static char	*char_u2(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'h')
	{
		if (sub[i - 2] == 'h')
		{
			var.char_uconv = va_arg(pa, unsigned int);
			var.tmp2 = ft_itoa_base(var.char_uconv, 10);
			return (var.tmp2);
		}
		else
		{
			var.short_unconv = va_arg(pa, unsigned int);
			var.tmp2 = ft_itoa_base(var.short_unconv, 10);
			return (var.tmp2);
		}
	}
	else
		var.tmp2 = char_u3(sub, var, pa, i);
	return (var.tmp2);
}

static char	*char_u(char *sub, t_pri var, va_list pa)
{
	int i;

	i = ft_strlen(sub) - 1;
	if (sub[i - 1] == 'z')
	{
		var.size_conv = va_arg(pa, size_t);
		var.tmp2 = ft_itoa_ulong(var.size_conv, 10);
	}
	else if (sub[i - 1] == 'j')
	{
		var.uintmax_conv = va_arg(pa, uintmax_t);
		var.tmp2 = ft_itoa_ulong(var.uintmax_conv, 10);
	}
	else if (sub[i - 1] == 'h' || sub[i - 1] == 'l')
		var.tmp2 = char_u2(sub, var, pa, i);
	else
	{
		var.uniconv = va_arg(pa, unsigned int);
		var.tmp2 = ft_itoa_base(var.uniconv, 10);
	}
	return (var.tmp2);
}

int			u_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.stock = char_u(sub, var, pa);
	free(var.tmp2);
	i = 0;
	if (var.stock[0] == '0' && ft_strlen(var.stock) == 1 && ft_strchr(sub, '.')
	!= NULL)
		var.ret = var.ret - 1;
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = min_pre(sub, var.stock, var);
	else
		var.tmp = ft_strdup(var.stock);
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
