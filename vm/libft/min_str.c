/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:27:37 by jcao              #+#    #+#             */
/*   Updated: 2016/04/08 15:13:34 by jcao             ###   ########.fr       */
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
		num = ft_strnew(ft_strlen(tmp2 + 1));
		num = ft_strcpy(num, tmp2);
		free(tmp);
		free(tmp2);
	}
	return (num);
}

static char	*space_count(int len, char *tmp)
{
	int i;

	i = 0;
	while (i < len)
	{
		tmp[i] = ' ';
		i++;
	}
	return (tmp);
}

static char	*str_left(t_pri var, char *stock, int len)
{
	var.tmp = ft_strnew(len - ft_strlen(stock));
	var.tmp = space_count((len - ft_strlen(stock)), var.tmp);
	var.res = ft_strjoin(stock, var.tmp);
	free(var.tmp);
	return (var.res);
}

static char	*str_right(t_pri var, char *stock, int len, char *sub)
{
	var.tmp = ft_strnew(len - ft_strlen(stock));
	var.tmp = space_count((len - ft_strlen(stock)), var.tmp);
	if (ft_strchr(sub, '0') != NULL && ft_strchr(sub, 'p') != NULL)
		var.res = ft_strjoin(stock, var.tmp);
	else
		var.res = ft_strjoin(var.tmp, stock);
	free(var.tmp);
	return (var.res);
}

char		*min_str(char *sub, char *stock, t_pri var, int i)
{
	var.num = ft_strnew(2);
	if (sub[i] == '1' || sub[i] == '2' || sub[i] == '3' || sub[i] == '4' ||
sub[i] == '5' || sub[i] == '6' || sub[i] == '7' || sub[i] == '8' ||
sub[i] == '9' || sub[i] == '0')
	{
		var.num[0] = sub[i];
		var.num = loop_join(sub, var.num, i);
		var.len = ft_atoi(var.num);
	}
	free(var.num);
	if (ft_strchr(sub, '-') != NULL)
	{
		if (ft_strlen(stock) < var.len)
			var.res = str_left(var, stock, var.len);
		else
			var.res = ft_strdup(stock);
	}
	else
	{
		if (ft_strlen(stock) < var.len)
			var.res = str_right(var, stock, var.len, sub);
		else
			var.res = ft_strdup(stock);
	}
	return (var.res);
}
