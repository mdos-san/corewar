/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmaj_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:47:03 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 12:07:31 by jcao             ###   ########.fr       */
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
	else if (format[i] == 'h')
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

int			cmaj_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	i = 0;
	var.char_unicode = va_arg(pa, wint_t);
	var.str = unicode_mask(var.char_unicode);
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = max_char(sub, var.str, var);
	else
		var.tmp = ft_strdup(var.str);
	while (check_flag(sub, i) == 0)
		i++;
	var.res = min_str(sub, var.tmp, var, i);
	if (ft_strchr(sub, 'h') == NULL)
		ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	free_str3(var.str, var.res, var.tmp);
	return (var.ret);
}
