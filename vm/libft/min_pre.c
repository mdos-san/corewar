/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_pre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:09:06 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 14:15:17 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*zero_count(int len, char *tmp)
{
	int i;

	i = 0;
	while (i < len)
	{
		tmp[i] = '0';
		i++;
	}
	return (tmp);
}

static char	*put_pre(t_pri var, char *stock, int len, char *sub)
{
	int i;

	i = 0;
	while (sub[i] != '.')
		i++;
	if ((ft_strchr(sub, 'p') != NULL) && (sub[i - 1] != '1' &&
	sub[i - 1] != '2' && sub[i - 1] != '3' && sub[i - 1] != '4' &&
	sub[i - 1] != '5' && sub[i - 1] != '6' && sub[i - 1] != '7' &&
	sub[i - 1] != '8' && sub[i - 1] != '9'))
	{
		var.tmp = ft_strnew(len - ft_strlen(stock));
		var.tmp = zero_count(len - 1, var.tmp);
		var.res = ft_strjoin(stock, var.tmp);
		free(var.tmp);
	}
	else
	{
		var.tmp = ft_strnew(len - ft_strlen(stock));
		var.tmp = zero_count((len - ft_strlen(stock)), var.tmp);
		var.res = ft_strjoin(var.tmp, stock);
		free(var.tmp);
	}
	return (var.res);
}

static char	*remove_neg(t_pri var, char *stock, unsigned long len, char *sub)
{
	int i;

	i = 0;
	var.tmp3 = ft_strnew(ft_strlen(stock));
	while (stock[i + 1] != '\0')
	{
		var.tmp3[i] = stock[i + 1];
		i++;
	}
	var.tmp3[i] = '\0';
	stock = ft_strnew(ft_strlen(var.tmp3));
	stock = ft_strcpy(stock, var.tmp3);
	free(var.tmp3);
	if (ft_strlen(stock) < len)
	{
		var.res = put_pre(var, stock, len, sub);
		var.tmp3 = ft_strjoin("-", var.res);
		free(var.res);
		var.res = ft_strnew(ft_strlen(var.tmp3));
		var.res = ft_strcpy(var.res, var.tmp3);
		free(var.tmp3);
	}
	return (var.res);
}

char		*min_pre(char *sub, char *stock, t_pri var)
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
	stock = except_pre(stock, var.len, sub);
	if (stock[0] == '-' && (ft_strlen(stock + 1) < var.len))
		var.res = remove_neg(var, stock, var.len, sub);
	else
	{
		if (ft_strlen(stock) < var.len)
			var.res = put_pre(var, stock, var.len, sub);
		else
			var.res = ft_strdup(stock);
	}
	return (var.res);
}
