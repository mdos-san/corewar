/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:22:58 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:38:42 by jcao             ###   ########.fr       */
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

static char	*replace_zero(char *res)
{
	int i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == ' ' || res[i] == 'x')
			res[i] = '0';
		i++;
	}
	res[1] = 'x';
	return (res);
}

char		*hashtag_x(char *res, char *str, t_pri var)
{
	var.i = 0;
	var.k = 0;
	while (res[var.i] == ' ' || res[var.i] == '0')
		var.i++;
	while (check_flag(str, var.k) == 0)
		var.k++;
	var.tmp2 = ft_strnew(var.k + 1);
	var.tmp2 = ft_strncpy(var.tmp2, str, var.k);
	if (ft_strchr(var.tmp2, '-') != NULL)
	{
		while (res[var.i] != ' ')
			var.i++;
		var.tmp = ft_strsub(res, 0, var.i);
	}
	else if (ft_strchr(str, '.') != NULL)
		var.tmp = ft_strdup(res);
	else
		var.tmp = ft_strsub(res, var.i, ft_strlen(res) - var.i + 1);
	var.res = ft_strjoin("0x", var.tmp);
	free(res);
	res = min_str(str, var.res, var, var.k);
	if (ft_strchr(var.tmp2, '0') != NULL && ft_strchr(var.tmp2, '-') == NULL)
		res = replace_zero(res);
	free_str3(var.tmp, var.tmp2, var.res);
	return (res);
}
