/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_headerfin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:56:25 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/06 15:39:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

char	*normeheader(int k, char *res, t_liste **tmp)
{
	while (k > 0)
	{
		res = ft_strcat(res, "\n");
		res = ft_strcat(res, tmp[0]->str);
		k--;
		tmp[0] = tmp[0]->next;
	}
	return (res);
}

char	*norme2(char *res, char **str)
{
	res = ft_strcat(res, "\n");
	res = ft_strcat(res, str[0]);
	free_line(str);
	return (res);
}

char	*create_headerfin(char *res, int j, t_liste *tmp, int i)
{
	int			k;
	t_liste		*tmp1;
	char		*str;

	k = 0;
	tmp1 = tmp->next;
	while (tmp1)
	{
		j = 0;
		while (tmp1->str[j] && tmp1->str[j] != '"')
			j++;
		if (tmp1->str[j])
		{
			res = ft_strcpy(res, &tmp->str[i]);
			tmp = tmp->next;
			res = normeheader(k, res, &tmp);
			if (!(str = ft_strsub(tmp->str, 0, j)))
				exit(0);
			res = norme2(res, &str);
			return (res);
		}
		k++;
		tmp1 = tmp1->next;
	}
	return (res);
}
