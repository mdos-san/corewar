/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:40:37 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 11:50:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		dump(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0)
			ft_printf("0x%.4x: ", i);
		ft_printf("%.2x ", cw->board[i]);
		if ((i + 1) % 32 == 0)
			ft_putchar('\n');
		++i;
	}
}

void		d(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%.2x ", cw->board[i]);
		if ((i + 1) % 64 == 0)
			ft_putchar('\n');
		++i;
	}
}

static int	die_recur(t_cw *cw, t_process *p, t_process *prev, int nb_live)
{
	int	ret;
	int	f;

	if (p != NULL)
	{
		nb_live += p->nb_live;
		if (p->nb_live > 0)
		{
			prev = p;
			p->nb_live = 0;
			f = 0;
		}
		else
		{
			if (prev == NULL)
				cw->process = p->next;
			else
				prev->next = p->next;
			f = 1;
		}
		ret = die_recur(cw, p->next, prev, nb_live);
		(f) ? free(p) : 0;
		return (ret);
	}
	return (nb_live);
}

static void	die(t_cw *cw, int *check)
{
	static int	max_check = 0;
	int			nb_live;

	nb_live = die_recur(cw, cw->process, NULL, 0);
	if (nb_live >= NBR_LIVE || max_check + 1 == MAX_CHECKS)
	{
		cw->cycle_to_die -= CYCLE_DELTA;
		max_check = 0;
	}
	else
		max_check++;
	*check = 0;
}

static void	exec_turn(t_cw *cw, int *turn)
{
	t_process *l;

	l = cw->process;
	while (l)
	{
		cw->ap = l;
		cw->param_error = 0;
		cw->normal = 1;
		l->pc = mod(l->pc, 0);
		if (l->is_waiting <= 0)
		{
			l->is_waiting = 1;
			l->waiting_turn = *turn + get_turn(cw->board[l->pc]) - 1;
			l->fct = cw->board[l->pc];
		}
		if (l->waiting_turn == *turn)
		{
			if (cw->board[l->pc] < 1 || 16 < cw->board[l->pc])
				cw->param_error = 1;
			cw->nb_readed = 0;
			cw->nb_param = 0;
			cw->fct_tab[l->fct](cw, l);
			if (cw->f_verbose && cw->nb_readed > 0)
			{
				ft_printf("ADV %d (0x%.4x -> 0x%.4x) ", cw->nb_readed, l->pc, l->pc + cw->nb_readed);
				verbose_print(cw, 0, 0, cw->nb_readed);
				ft_putchar('\n');
			}
			l->pc += cw->nb_readed;
			l->pc %= MEM_SIZE;
			l->is_waiting = 0;
		}
		l = l->next;
	}
}

int			main(int ac, char **av)
{
	t_cw		cw;
	int			check;

	cw = cw_init(ac, av);
	cw.turn = 1;
	check = 0;
	cw_parse(&cw);
	while (cw.process)
	{
		if (cw.turn - 1 == cw.f_dump || cw.turn - 1 == cw.f_d)
			break ;
		if (cw.cycle_to_die <= 0)
			break ;
		if (check >= cw.cycle_to_die)
			die(&cw, &check);
		exec_turn(&cw, &cw.turn);
		if (cw.f_v == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(0, 0,
			"Turn: %d, Process: %d, Cycle to die: %d, Instructions: %lld\n",
			cw.turn, process_count(cw.process), cw.cycle_to_die, cw.ins);
			board_print(&cw);
			refresh();
		}
		++cw.turn;
		++check;
	}
	if (cw.f_v == 1)
		endwin();
	if (cw.process == NULL || cw.cycle_to_die <= 0)
		print_winner(&cw);
	else if (cw.f_d != -1)
		d(&cw);
	else if (cw.f_dump != -1)
		dump(&cw);
	return (1);
}
