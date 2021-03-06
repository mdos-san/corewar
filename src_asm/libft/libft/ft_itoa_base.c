/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:08:31 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 14:31:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long nbr, unsigned int base)
{
	int			i;
	long long	mod;
	char		buf[1024];
	long long	neg;

	i = 0;
	ft_bzero(buf, 1024);
	if (nbr == 0)
		return (ft_strdup("0"));
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[1022 - i] = mod * neg + 48;
		else
		{
			mod -= 10;
			buf[1022 - i] = mod * neg + 97;
		}
		nbr /= base;
		++i;
	}
	(neg == -1) ? buf[1022 - i] = '-' : 0;
	return (ft_strdup(buf + 1022 - i + 1 - ((neg == -1) ? 1 : 0)));
}
