/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaj_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:52:59 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 13:10:34 by jcao             ###   ########.fr       */
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

static char	*max_char(char *sub, char *stock, t_pri var, wchar_t *str)
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
	var.len = except_smaj(str, var.len);
	if (ft_strlen(stock) > var.len)
		var.tmp = ft_strsub(stock, 0, var.len);
	else
	{
		var.tmp = ft_strnew(ft_strlen(stock));
		var.tmp = ft_strcpy(var.tmp, stock);
	}
	return (var.tmp);
}

static char	*link_charuni(wchar_t *str)
{
	int		i;
	char	*tmp;
	char	*stock;
	char	*tmp2;

	i = 0;
	stock = NULL;
	while (str[i] != '\0')
	{
		tmp = unicode_masks(str[i]);
		if (stock == NULL)
			stock = ft_strdup(tmp);
		else
		{
			tmp2 = ft_strdup(stock);
			free(stock);
			stock = ft_strjoin(tmp2, tmp);
			free(tmp2);
		}
		free(tmp);
		i++;
	}
	return (stock);
}

int			smaj_conv(char *sub, t_pri var, va_list pa)
{
	var.i = 0;
	var.str_unicode = va_arg(pa, wchar_t *);
	if (var.str_unicode == NULL)
		var.str = ft_strdup("(null)");
	else if (ft_strlen((char *)var.str_unicode) == 0)
		var.str = ft_strdup("");
	else
		var.str = link_charuni(var.str_unicode);
	if (ft_strchr(sub, '.') != NULL)
		var.tmp = max_char(sub, var.str, var, var.str_unicode);
	else
		var.tmp = ft_strdup(var.str);
	while (check_flag(sub, var.i) == 0)
		var.i++;
	var.res = min_str(sub, var.tmp, var, var.i);
	var.tmp2 = ft_strnew(var.i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, var.i);
	var.res = fucking_flag(var.tmp2, var.res, var, var.sub);
	ft_putstr(var.res);
	var.ret = var.ret + ft_strlen(var.res + 1);
	if (ft_strlen(var.res) == 0)
		var.ret = var.ret - 1;
	free_str(var.res, var.tmp, var.tmp2, var.str);
	return (var.ret);
}
