/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_masks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:01:19 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 10:49:00 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*fill_zero(char *res)
{
	int i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[i] == 'x')
			res[i] = '0';
		i++;
	}
	return (res);
}

static char	*fill_tab(char *tab, char *bin, char *res)
{
	int i;
	int k;

	i = 0;
	k = 0;
	res = ft_strdup(tab);
	while (res[i] != '\0')
		i++;
	i--;
	while (bin[k] != '\0')
		k++;
	k--;
	while (k >= 0)
	{
		if (res[i] == 'x')
		{
			res[i] = bin[k];
			k--;
		}
		i--;
	}
	res = fill_zero(res);
	return (res);
}

char		*unicode_masks(wchar_t s_uni)
{
	char	*tab[4];
	char	*binary;
	int		len;
	char	*res;

	res = NULL;
	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	binary = ft_itoa_base(s_uni, 2);
	len = ft_strlen(binary);
	if (len <= 7)
		res = fill_tab(tab[0], binary, res);
	else if (len <= 11)
		res = fill_tab(tab[1], binary, res);
	else if (len <= 16)
		res = fill_tab(tab[2], binary, res);
	else
		res = fill_tab(tab[3], binary, res);
	res = split_tab(res);
	free(binary);
	return (res);
}
