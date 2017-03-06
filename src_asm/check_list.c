/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:48:15 by jcao              #+#    #+#             */
/*   Updated: 2017/01/23 14:52:39 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int			check_list(t_parse **list, char *str)
{
	t_parse *tmp;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->str, str) == 0)
			return (1);
		else
			tmp = tmp->next;
	}
	if (ft_strcmp(tmp->str, str) == 0)
		return (1);
	else
		return (-1);
	return (-1);
}
