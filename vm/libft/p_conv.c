/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 16:18:36 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 16:25:00 by jcao             ###   ########.fr       */
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

static char	*char_p(t_pri var, va_list pa)
{
	var.voidconv = va_arg(pa, void *);
	var.tmp2 = ft_itoa_base((long long)var.voidconv, 16);
	if (var.tmp2[0] == '0' && ft_strlen(var.tmp2) == 1)
	{
		free(var.tmp2);
		var.tmp2 = ft_strdup("0x0");
	}
	return (var.tmp2);
}

static char	*add(char *res)
{
	char *tmp;

	tmp = ft_strjoin("0x", res);
	free(res);
	res = ft_strdup(tmp);
	free(tmp);
	return (res);
}

int			p_conv(char *sub, t_pri var, va_list pa)
{
	int i;

	var.stock = char_p(var, pa);
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
	if (var.tmp[1] != 'x')
		var.tmp = add(var.tmp);
	var.res = min_str(sub, var.tmp, var, i);
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	var.res = fucking_flag(var.tmp2, var.res, var, var.sub);
	ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	free_str(var.tmp, var.tmp2, var.res, var.stock);
	return (var.ret);
}
