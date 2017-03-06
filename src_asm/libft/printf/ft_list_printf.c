/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:44:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/21 10:38:21 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_lst	*new_lst(char *src)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->next = NULL;
	new->str = ft_strdup(src);
	new->size = (int)ft_strlen(new->str);
	return (new);
}

void	ft_list_push_back(t_lst **begin_list, char *str)
{
	t_lst *new;
	t_lst *tmp;

	new = new_lst(str);
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		tmp = *begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_list_push_front(t_lst **begin_list, char *str)
{
	t_lst *new;

	new = new_lst(str);
	if (*begin_list == NULL)
		*begin_list = new;
	else
	{
		new->next = *begin_list;
		*begin_list = new;
	}
}

void	ft_free_list(t_lst *begin_list)
{
	t_lst *tmp;

	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		ft_memdel((void **)&tmp->str);
		ft_memdel((void **)&tmp);
	}
	begin_list = NULL;
}
