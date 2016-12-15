/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except_smaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 16:37:45 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:29:44 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_wchar(wchar_t c)
{
	char		*binary;
	int			len;

	binary = ft_itoa_base(c, 2);
	len = ft_strlen(binary);
	if (len <= 7)
		return (1);
	else if (len <= 11)
		return (2);
	else if (len <= 16)
		return (3);
	else
		return (4);
}

int			except_smaj(wchar_t *str, int len)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (len > ret)
	{
		ret = ret + len_wchar(str[i]);
		i++;
	}
	if (len != ret)
		ret = ret - len_wchar(str[i]);
	return (ret);
}
