/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:31:05 by jcao              #+#    #+#             */
/*   Updated: 2017/02/11 15:08:54 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

static	t_parse	*fill_list(t_parse *tmp, t_parse *ptr, t_asm *var, int i)
{
	while (ptr->next != NULL)
		ptr = ptr->next;
	tmp->str = ft_strnew(var->k + 1);
	tmp->str = ft_strncpy(tmp->str, &var->stock[i], var->k);
	ptr->next = tmp;
	tmp->next = NULL;
	return (var->list);
}

static	t_parse	*create_elem(t_parse **list, t_asm *var, int i)
{
	t_parse		*tmp;
	t_parse		*ptr;
	int			index;

	ptr = *list;
	var->k = 0;
	index = i;
	tmp = (t_parse *)malloc(sizeof(*tmp));
	while (var->stock[i] != ':')
	{
		var->k++;
		i++;
	}
	i = index;
	if (var->list == NULL)
	{
		tmp->str = ft_strnew(var->k + 1);
		tmp->str = ft_strncpy(tmp->str, &var->stock[i], var->k);
		tmp->next = NULL;
		*list = tmp;
	}
	else
		var->list = fill_list(tmp, ptr, var, i);
	return (var->list);
}

t_parse			*create_list(t_asm *var)
{
	int		i;
	int		index;

	i = 0;
	while (var->stock[i] != '\0')
	{
		if (var->stock[i] == ':')
		{
			if (var->stock[i - 1] != '%')
			{
				index = i;
				while (ft_isspace(var->stock[i]) != 1)
					i--;
				i++;
				var->list = create_elem(&var->list, var, i);
				i = index;
			}
		}
		i++;
	}
	return (var->list);
}
