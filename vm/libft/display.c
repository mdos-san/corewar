/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:39:30 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 09:59:53 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	display2(char *sub, t_pri var, va_list pa)
{
	if (ft_strchr(sub, 'u') != NULL)
		var.ret = u_conv(sub, var, pa);
	else if (ft_strchr(sub, 'U') != NULL)
		var.ret = umaj_conv(sub, var, pa);
	else if (ft_strchr(sub, 'x') != NULL)
		var.ret = x_conv(sub, var, pa);
	else if (ft_strchr(sub, 'X') != NULL)
		var.ret = xmaj_conv(sub, var, pa);
	else if (ft_strchr(sub, 'p') != NULL)
		var.ret = p_conv(sub, var, pa);
	else if (ft_strchr(sub, 'c') != NULL)
		var.ret = c_conv(sub, var, pa);
	else if (ft_strchr(sub, 's') != NULL)
		var.ret = s_conv(sub, var, pa);
	else
		var.ret = no_conv(sub, var);
	return (var.ret);
}

int			display(char *sub, t_pri var, va_list pa)
{
	if (ft_strchr(sub, 'S') != NULL || (ft_strchr(sub, 's') != NULL &&
	ft_strchr(sub, 'l') != NULL))
		var.ret = smaj_conv(sub, var, pa);
	else if (ft_strchr(sub, 'C') != NULL || (ft_strchr(sub, 'c') != NULL &&
	ft_strchr(sub, 'l') != NULL))
		var.ret = cmaj_conv(sub, var, pa);
	else if (ft_strchr(sub, '%') != NULL)
		var.ret = percent_conv(sub, var);
	else if (ft_strchr(sub, 'd') != NULL)
		var.ret = di_conv(sub, var, pa);
	else if (ft_strchr(sub, 'O') != NULL)
		var.ret = omaj_conv(sub, var, pa);
	else if (ft_strchr(sub, 'i') != NULL)
		var.ret = di_conv(sub, var, pa);
	else if (ft_strchr(sub, 'o') != NULL)
		var.ret = o_conv(sub, var, pa);
	else if (ft_strchr(sub, 'D') != NULL)
		var.ret = dmaj_conv(sub, var, pa);
	else
		var.ret = display2(sub, var, pa);
	return (var.ret);
}
