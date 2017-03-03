/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:58:01 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 12:03:11 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	assign_turn(t_cw *cw, t_process *l, int *turn)
{
	l->is_waiting = 1;
	l->waiting_turn = *turn + get_turn(cw->board[l->pc]) - 1;
	l->fct = cw->board[l->pc];
}

static void	verbose(t_cw *cw, t_process *l)
{
	ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", cw->nb_readed, l->pc, l->pc + cw->nb_readed);
	verbose_print(cw, 0, 0, cw->nb_readed);
	ft_putchar('\n');
}

void		exec_turn(t_cw *cw, int *turn)
{
	t_process *l;

	l = cw->process;
	while (l)
	{
		cw->ap = l;
		cw->param_error = 0;
		cw->normal = 1;
		l->pc = mod(l->pc, 0);
		(l->is_waiting <= 0) ? assign_turn(cw, l, turn) : (void)0;
		if (l->waiting_turn == *turn)
		{
			if (cw->board[l->pc] < 1 || 16 < cw->board[l->pc])
				cw->param_error = 1;
			cw->nb_readed = 0;
			cw->nb_param = 0;
			cw->fct_tab[l->fct](cw, l);
			if (cw->f_verbose && cw->nb_readed > 0)
				verbose(cw, l);
			l->pc += cw->nb_readed;
			l->pc %= MEM_SIZE;
			l->is_waiting = 0;
		}
		l = l->next;
	}
}
