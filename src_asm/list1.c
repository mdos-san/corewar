/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 05:16:28 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/27 14:55:32 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static t_liste		*new_list(char *str)
{
	t_liste *new;

	if (!(new = (t_liste *)malloc(sizeof(t_liste))))
		return (NULL);
	new->next = NULL;
	if (!(new->str = ft_strdup(str)))
		return (NULL);
	return (new);
}

t_liste				*push_back_l(t_liste *begin_list, char *str)
{
	t_liste *new;
	t_liste *tmp;

	if (!(new = new_list(str)))
		return (NULL);
	if (begin_list == NULL)
		begin_list = new;
	else
	{
		tmp = begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (begin_list);
}

void				ft_free_list_l(t_liste **begin_list)
{
	t_liste *tmp;
	t_liste *tmp1;

	tmp1 = begin_list[0];
	if (tmp1 && tmp1->next)
	{
		tmp1 = tmp1->next;
		while (tmp1 != NULL)
		{
			tmp = tmp1;
			tmp1 = tmp1->next;
			free(tmp->str);
			ft_memdel((void **)&tmp);
		}
	}
	if (begin_list[0])
	{
		free(begin_list[0]->str);
		free(begin_list[0]);
	}
	tmp1 = NULL;
	begin_list[0] = NULL;
}
