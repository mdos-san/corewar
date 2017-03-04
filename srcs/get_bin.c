/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:17:55 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/04 13:18:12 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_bin(char *buf, int nbr, int base)
{
	int	i;
	int	mod;
	int	neg;

	i = 0;
	ft_bzero(buf, 9);
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[7 - i] = (char)(mod * neg + 48);
		else
		{
			mod -= 10;
			buf[7 - i] = (char)(mod * neg + 97);
		}
		nbr /= base;
		++i;
	}
	while (i < 8)
	{
		buf[7 - i] = '0';
		++i;
	}
}
