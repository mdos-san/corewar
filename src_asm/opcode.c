/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:06:17 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/27 14:31:05 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int				*ft_calc(int *bin, int i, int *k, char **str)
{
	int j;

	j = 0;
	if (str[i][j] == ',')
		j++;
	if (str[i][j] == 'r' && ft_isdigit(str[i][j + 1]) == 1)
	{
		bin[++k[0]] = 0;
		bin[++k[0]] = 1;
	}
	if (str[i][j] == DIRECT_CHAR)
	{
		bin[++k[0]] = 1;
		bin[++k[0]] = 0;
	}
	if ((str[i][j] == '-' && ft_isdigit(str[i][j + 1])) ||
			ft_isdigit(str[i][j]))
	{
		bin[++k[0]] = 1;
		bin[++k[0]] = 1;
	}
	return (bin);
}

unsigned char	opcode(char **str, int i, int size_str)
{
	int				*bin;
	unsigned char	res;
	int				k;

	if (!(bin = (int *)malloc(sizeof(int) * 8)))
		exit(0);
	res = 0;
	k = -1;
	while (++k < 8)
		bin[k] = 0;
	k = -1;
	while (i < size_str)
	{
		bin = ft_calc(bin, i, &k, str);
		i++;
	}
	k = -1;
	while (++k < 8)
		res = res * 2 + bin[k];
	ft_memdel((void *)&bin);
	return (res);
}
