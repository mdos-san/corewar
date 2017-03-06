/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:40:37 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 11:46:01 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

static void	die(t_cw *cw)
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
	cw->check = 0;
}

static void	display(t_cw *cw)
{
	attron(COLOR_PAIR(1));
	mvprintw(0, 0,
	"Turn: %d, Process: %d, Cycle to die: %d, Instructions: %lld\n",
	cw->turn, process_count(cw->process), cw->cycle_to_die, cw->ins);
	board_print(cw);
	refresh();
}

int			main(int ac, char **av)
{
	t_cw		cw;

	cw = cw_init(ac, av);
	cw_parse(&cw);
	while (cw.process)
	{
		if (cw.turn - 1 == cw.f_dump || cw.turn - 1 == cw.f_d)
			break ;
		if (cw.cycle_to_die <= 0)
			break ;
		(cw.check >= cw.cycle_to_die) ? die(&cw) : (void)0;
		exec_turn(&cw, &cw.turn);
		(cw.f_v == 1) ? display(&cw) : (void)0;
		++cw.turn;
		++cw.check;
	}
	(cw.f_v) ? endwin() : 0;
	if (cw.process == NULL || cw.cycle_to_die <= 0)
		print_winner(&cw);
	else if (cw.f_d)
		d(&cw);
	else if (cw.f_dump)
		dump(&cw);
	cw_exit(&cw, 0, NULL);
	return (1);
}
