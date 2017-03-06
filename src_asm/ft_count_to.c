/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:44 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/04 16:38:51 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int		count_1(t_e *e, int i, char *str)
{
	int res;
	int j;

	res = 0;
	j = -1;
	while (i - ++j >= 0)
	{
		if (j == 0)
			res += e->tab[i - j].nb_octet;
		res -= e->tab[i - j].nb_octet;
		if ((e->tab[i - j].cmd == 3 || e->tab[i - j].cmd == 2) &&
				ft_strcmp(e->tab[i - j].ft, str) == 0)
		{
			free_line(&str);
			return (res);
		}
	}
	free_line(&str);
	return (0);
}

char	*norme3(char *str, char *str1)
{
	if (str1[ft_strlen(str1) - 1] == ',')
	{
		if (!(str = ft_strsub(str1, 2, ft_strlen(&str1[2]) - 1)))
			exit(0);
	}
	else if (!(str = ft_strsub(str1, 2, ft_strlen(&str1[2]))))
		exit(0);
	return (str);
}

int		ft_count_to(t_e *e, int i, char *str1)
{
	int		res;
	int		j;
	char	*str;

	str = NULL;
	str = norme3(str, str1);
	res = 0;
	j = -1;
	while (i + ++j < e->nb_instruct)
	{
		res += e->tab[i + j].nb_octet;
		if ((e->tab[i + j].cmd == 3 || e->tab[i + j].cmd == 2) &&
				ft_strcmp(str, e->tab[i + j].ft) == 0)
		{
			if (e->tab[i + j].cmd == 2)
				res -= e->tab[i + j].nb_octet;
			free_line(&str);
			return (res);
		}
	}
	res = count_1(e, i, str);
	return (res);
}
