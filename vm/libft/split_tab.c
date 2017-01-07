/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:24:32 by jcao              #+#    #+#             */
/*   Updated: 2016/04/11 11:55:50 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*split_tab3(char *res)
{
	char	*tab[4];
	int		num[4];

	tab[0] = ft_strsub(res, 0, 8);
	tab[1] = ft_strsub(res, 8, 16);
	tab[2] = ft_strsub(res, 16, 24);
	tab[3] = ft_strsub(res, 24, 32);
	num[0] = conv_bin(tab[0]);
	num[1] = conv_bin(tab[1]);
	num[2] = conv_bin(tab[2]);
	num[3] = conv_bin(tab[3]);
	free(res);
	res = ft_strnew(5);
	res[0] = num[0];
	res[1] = num[1];
	res[2] = num[2];
	res[3] = num[3];
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	free(tab[3]);
	return (res);
}

static char	*split_tab2(char *res)
{
	char	*tab[3];
	int		num[3];

	tab[0] = ft_strsub(res, 0, 8);
	tab[1] = ft_strsub(res, 8, 16);
	tab[2] = ft_strsub(res, 16, 24);
	num[0] = conv_bin(tab[0]);
	num[1] = conv_bin(tab[1]);
	num[2] = conv_bin(tab[2]);
	free(res);
	res = ft_strnew(4);
	res[0] = num[0];
	res[1] = num[1];
	res[2] = num[2];
	free(tab[0]);
	free(tab[1]);
	free(tab[2]);
	return (res);
}

static char	*split_tab1(char *res)
{
	char	*tab[2];
	int		num[2];

	tab[0] = ft_strsub(res, 0, 8);
	tab[1] = ft_strsub(res, 8, 16);
	num[0] = conv_bin(tab[0]);
	num[1] = conv_bin(tab[1]);
	free(res);
	res = ft_strnew(3);
	res[0] = num[0];
	res[1] = num[1];
	free(tab[0]);
	free(tab[1]);
	return (res);
}

char		*split_tab(char *res)
{
	char	*tab[1];
	int		num;

	if (ft_strlen(res) == 8)
	{
		tab[0] = ft_strsub(res, 0, 8);
		num = conv_bin(tab[0]);
		free(res);
		res = ft_strnew(2);
		res[0] = num;
		free(tab[0]);
	}
	else if (ft_strlen(res) == 16)
		res = split_tab1(res);
	else if (ft_strlen(res) == 24)
		res = split_tab2(res);
	else
		res = split_tab3(res);
	return (res);
}
