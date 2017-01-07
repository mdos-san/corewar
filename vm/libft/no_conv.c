/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:21:19 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 15:58:42 by jcao             ###   ########.fr       */
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

int			no_conv(char *sub, t_pri var)
{
	int i;

	i = ft_strlen(sub) - 1;
	var.convc = sub[i];
	i = 0;
	while (check_flag(sub, i) == 0)
		i++;
	var.tmp2 = ft_strnew(i + 1);
	var.tmp2 = ft_strncpy(var.tmp2, sub, i);
	if (ft_strchr(var.tmp2, '0') != NULL)
		var.ret = min_char0(sub, var.convc, var, i);
	else
		var.ret = min_char(sub, var.convc, var, i);
	free(var.tmp2);
	return (var.ret);
}
