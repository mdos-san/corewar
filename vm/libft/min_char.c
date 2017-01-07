/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:27:32 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 11:17:28 by jcao             ###   ########.fr       */
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

static int	str_left(t_pri var, int convc)
{
	ft_putchar(convc);
	var.tmp2 = ft_strnew(var.len - 1);
	var.tmp2 = space_count((var.len - 1), var.tmp2);
	ft_putstr(var.tmp2);
	var.ret = var.ret + ft_strlen(var.tmp2);
	free(var.tmp2);
	return (var.ret);
}

static int	str_right(t_pri var, int convc)
{
	var.tmp2 = ft_strnew(var.len - 1);
	var.tmp2 = space_count((var.len - 1), var.tmp2);
	ft_putstr(var.tmp2);
	ft_putchar(convc);
	var.ret = var.ret + ft_strlen(var.tmp2);
	free(var.tmp2);
	return (var.ret);
}

int			min_char(char *sub, int convc, t_pri var, int i)
{
	var.num = ft_strnew(2);
	if (sub[i] == '1' || sub[i] == '2' || sub[i] == '3' ||
sub[i] == '4' || sub[i] == '5' || sub[i] == '6' || sub[i] ==
'7' || sub[i] == '8' || sub[i] == '9' || sub[i] == '0')
	{
		var.num[0] = sub[i];
		var.num = loop_join(sub, var.num, i);
		var.len = ft_atoi(var.num);
	}
	free(var.num);
	if (ft_strchr(var.sub, '-') != NULL)
	{
		if (var.len > 1)
			var.ret = str_left(var, convc);
	}
	else
	{
		if (var.len > 1)
			var.ret = str_right(var, convc);
		else
			ft_putchar(convc);
	}
	return (var.ret);
}
