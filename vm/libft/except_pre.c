/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   except_pre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 11:17:41 by jcao              #+#    #+#             */
/*   Updated: 2016/03/30 16:14:46 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*except_pre(char *stock, int len, char *sub)
{
	if (stock[0] == '0' && ft_strlen(stock) == 1 && len == 0 &&
	ft_strchr(sub, 'o') == NULL)
	{
		free(stock);
		stock = ft_strdup("");
		return (stock);
	}
	else if (stock[0] == '0' && stock[1] == 'x' && stock[2] == '0' &&
	ft_strlen(stock) == 3 && len == 0)
	{
		free(stock);
		stock = ft_strdup("");
		return (stock);
	}
	else if (stock[0] == '0' && ft_strlen(stock) == 1 && len == 0 &&
	ft_strchr(sub, 'o') != NULL && ft_strchr(sub, '#') == NULL)
	{
		free(stock);
		stock = ft_strdup("");
		return (stock);
	}
	return (stock);
}
