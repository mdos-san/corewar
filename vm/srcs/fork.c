/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:33:35 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 11:47:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	frk(t_cw *cw, t_process *p)
{
	short		j;
	t_process	*child;
	int			i;

	i = 0;
	j = 0;
	((unsigned char *)&j)[1] = cw->board[mod(p->pc, 1)];
	((unsigned char *)&j)[0] = cw->board[mod(p->pc, 2)];
	j = idx_mod(j);
	child = process_new(&cw->process, p->nb_champ,
			mod(p->pc, j), p->color_nb);
	if (child == NULL)
		cw_exit(cw, 1, "Malloc fail, can't create a new process.");
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}
	child->carry = p->carry;
	child->nb_live = p->nb_live;
	cw->nb_readed = 3;
}

void	lfrk(t_cw *cw, t_process *p)
{
	short		j;
	t_process	*child;
	int			i;

	i = 0;
	j = 0;
	((unsigned char *)&j)[1] = cw->board[mod(p->pc, 1)];
	((unsigned char *)&j)[0] = cw->board[mod(p->pc, 2)];
	child = process_new(&cw->process, p->nb_champ,
			mod(p->pc, j), p->color_nb);
	if (child == NULL)
		cw_exit(cw, 1, "Malloc fail, can't create a new process.");
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}
	child->carry = p->carry;
	child->nb_live = p->nb_live;
	cw->nb_readed = 3;
}
