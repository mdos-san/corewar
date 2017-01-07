/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:33:01 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 15:55:25 by jcao             ###   ########.fr       */
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

static char	*loop_join(char *sub, char *num, int i)
{
	char *tmp;
	char *tmp2;

	while (sub[i + 1] == '1' || sub[i + 1] == '2' || sub[i + 1] == '3' ||
sub[i + 1] == '4' || sub[i + 1] == '5' || sub[i + 1] == '6' || sub[i] ==
'7' || sub[i + 1] == '8' || sub[i + 1] == '9' || sub[i + 1] == '0')
	{
		i++;
		tmp = ft_strnew(2);
		tmp[0] = sub[i];
		tmp2 = ft_strjoin(num, tmp);
		free(num);
		num = ft_strnew(ft_strlen(tmp2));
		num = ft_strcpy(num, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (num);
}

static char	*max_char(char *sub, char *stock, t_pri var)
{
	var.i = 0;
	var.num = ft_strnew(2);
	while (sub[var.i] != '.')
		var.i++;
	var.i++;
	if (sub[var.i] == '1' || sub[var.i] == '2' || sub[var.i] == '3' ||
sub[var.i] == '4' || sub[var.i] == '5' || sub[var.i] == '6' || sub[var.i] ==
'7' || sub[var.i] == '8' || sub[var.i] == '9' || sub[var.i] == '0')
	{
		var.num[0] = sub[var.i];
		var.num = loop_join(sub, var.num, var.i);
		var.len = ft_atoi(var.num);
	}
	free(var.num);
	if (ft_strlen(stock) > var.len)
	{
		var.tmp = ft_strnew(var.len);
		var.tmp = ft_strncpy(var.tmp, stock, var.len);
	}
	else
	{
		var.tmp = ft_strnew(ft_strlen(stock));
		var.tmp = ft_strcpy(var.tmp, stock);
	}
	return (var.tmp);
}

int			s_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.str = va_arg(pa, char *);
	i = 0;
	if (var.str == NULL)
		var.str = "(null)";
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = max_char(sub, var.str, var);
	else
		var.tmp = ft_strdup(var.str);
	while (check_flag(sub, i) == 0)
		i++;
	var.res = min_str(sub, var.tmp, var, i);
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	var.res = fucking_flag(var.tmp2, var.res, var, var.sub);
	ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	if (ft_strlen(var.res) == 0)
		var.ret = var.ret - 1;
	free(var.res);
	free(var.tmp);
	free(var.tmp2);
	return (var.ret);
}
