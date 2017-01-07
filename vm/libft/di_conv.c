/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:23:35 by jcao              #+#    #+#             */
/*   Updated: 2016/04/07 16:59:28 by jcao             ###   ########.fr       */
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

static char	*char_di3(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'l')
	{
		if (sub[i - 2] == 'l')
		{
			var.longlong = va_arg(pa, long long);
			var.tmp2 = ft_itoa(var.longlong);
			return (var.tmp2);
		}
		else
		{
			var.longint = va_arg(pa, long);
			var.tmp2 = ft_itoa(var.longint);
			return (var.tmp2);
		}
	}
	return (var.tmp2);
}

static char	*char_di2(char *sub, t_pri var, va_list pa, int i)
{
	if (sub[i - 1] == 'h')
	{
		if (sub[i - 2] == 'h')
		{
			var.char_conv = va_arg(pa, int);
			var.tmp2 = ft_itoa(var.char_conv);
			return (var.tmp2);
		}
		else
		{
			var.short_conv = va_arg(pa, int);
			var.tmp2 = ft_itoa(var.short_conv);
			return (var.tmp2);
		}
	}
	else
		var.tmp2 = char_di3(sub, var, pa, i);
	return (var.tmp2);
}

static char	*char_di(char *sub, t_pri var, va_list pa)
{
	int i;

	i = ft_strlen(sub) - 1;
	if (sub[i - 1] == 'z')
	{
		var.size_conv = va_arg(pa, size_t);
		var.tmp2 = ft_itoa(var.size_conv);
	}
	else if (sub[i - 1] == 'j')
	{
		var.intmax_conv = va_arg(pa, intmax_t);
		var.tmp2 = ft_itoa(var.intmax_conv);
	}
	else if (sub[i - 1] == 'h' || sub[i - 1] == 'l')
		var.tmp2 = char_di2(sub, var, pa, i);
	else
	{
		var.convdi = va_arg(pa, int);
		var.tmp2 = ft_itoa(var.convdi);
	}
	return (var.tmp2);
}

int			di_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.stock = char_di(sub, var, pa);
	free(var.tmp2);
	i = 0;
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = min_pre(sub, var.stock, var);
	else
		var.tmp = ft_strdup(var.stock);
	while (check_flag(sub, i) == 0)
		i++;
	var.res = min_str(sub, var.tmp, var, i);
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	if (sub[0] == '.' && ft_strlen(var.stock) == 0)
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
