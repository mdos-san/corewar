/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:07:47 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:31:10 by jcao             ###   ########.fr       */
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

char		*hashtag_o(char *res, char *str, t_pri var)
{
	int k;

	var.i = 0;
	k = 0;
	while (res[var.i] == ' ')
		var.i++;
	while (check_flag(str, k) == 0)
		k++;
	var.tmp2 = ft_strnew(k + 1);
	var.tmp2 = ft_strncpy(var.tmp2, str, k);
	if (ft_strchr(str, '-') != NULL)
	{
		while (res[var.i] != ' ')
			var.i++;
		var.tmp = ft_strsub(res, 0, var.i);
	}
	else
		var.tmp = ft_strsub(res, var.i, ft_strlen(res) - var.i + 1);
	free(var.tmp2);
	var.tmp2 = ft_strjoin("0", var.tmp);
	free(res);
	res = min_str(str, var.tmp2, var, k);
	free(var.tmp);
	free(var.tmp2);
	return (res);
}
