/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:54:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/13 20:23:15 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_wint(t_env2 *env2, wint_t wint)
{
	char *str;

	str = ft_memalloc(5);
	if (wint <= 0x7F)
		str[0] = wint;
	else if (wint <= 0x7FF)
	{
		str[0] = ((wint & 0x07c0) >> 6) + 0xc0;
		str[1] = (wint & 0x003F) + 0x80;
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = ((wint & 0xF000) >> 12) + 0xE0;
		str[1] = ((wint & 0x0Fc0) >> 6) + 0x80;
		str[2] = (wint & 0x003F) + 0x80;
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = ((wint & 0x1c0000) >> 18) + 0xF0;
		str[1] = ((wint & 0x03F000) >> 12) + 0x80;
		str[2] = ((wint & 0x0Fc0) >> 6) + 0x80;
		str[3] = (wint & 0x003F) + 0x80;
	}
	env2->str = ft_strjoin_free(env2->str, env2->str, str);
	ft_memdel((void **)&str);
}
