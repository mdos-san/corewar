/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:12:17 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 11:29:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	reg_init(int *r)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		r[i] = 0;
		++i;
	}
}

static void	push_front(t_process **b, t_process *e)
{
	e->next = *b;
	*b = e;
}

t_process	*process_new(t_process **act, int champ, int pc, int color_nb)
{
	t_process	*new;

	new = (t_process*)malloc(sizeof(t_process));
	if (new != NULL)
	{
		new->nb_champ = champ;
		new->pc = pc;
		new->pc %= MEM_SIZE;
		new->is_waiting = 0;
		new->waiting_turn = 0;
		new->nb_live = 0;
		new->carry = 0;
		new->color_nb = color_nb;
		new->next = NULL;
		reg_init(new->r);
		new->r[0] = champ;
		if (*act == NULL)
			*act = new;
		else
			push_front(act, new);
	}
	return (new);
}

int			process_count(t_process *l)
{
	int	i;

	i = 0;
	while (l)
	{
		++i;
		l = l->next;
	}
	return (i);
}
