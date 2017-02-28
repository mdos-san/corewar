/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:40:37 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/28 16:31:04 by mdos-san         ###   ########.fr       */
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

static void	die(t_cw *cw, int *check)
{
	static int	max_check = 0;
	int			nb_live;
	t_process	*l;
	t_process	*prev;

	l = cw->process;
	nb_live = 0;
	prev = NULL;
	while (l)
	{
		if (l->nb_live > 0)
		{
			nb_live += l->nb_live;
			prev = l;
		}
		else
		{
			if (prev != NULL)
			{
				prev->next = l->next;
				free(l);
				l = prev;
			}
			else
			{
				cw->process = l->next;
				free(l);
				if (process_count(cw->process) == 0)
				{
					if (cw->f_v == 1)
						endwin();
					exit(0);
				}
				l = cw->process;
			}
		}
		if (l)
		{
			l->nb_live = 0;
			l = l->next;
		}
	}
	if (nb_live >= NBR_LIVE || max_check + 1 == MAX_CHECKS)
	{
//		if (cw->cycle_to_die - CYCLE_DELTA > 0)
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
		if (l->is_waiting <= 0)
		{
			l->is_waiting = 1;
			l->waiting_turn = *turn + get_turn(cw->board[l->pc]) - 1;
			l->fct = cw->board[l->pc];
//			if (cw->board[l->pc] == 1)
//				l->nb_live++;
		}
		if (l->waiting_turn == *turn)
		{
			if (cw->board[l->pc] < 1 || 16 < cw->board[l->pc])
				cw->param_error = 1;
			if (cw->f_verbose && cw->board[l->pc] != 9
			&& 1 <= cw->board[l->pc] && cw->board[l->pc] <= 16)
			{
				++cw->ins;
				ft_printf("%.2x ", cw->board[l->pc]);
				cw->fct_tab[l->fct](cw, l);
				ft_putchar('\n');
			}
			else
			{
				cw->normal = 0;
				cw->fct_tab[l->fct](cw, l);
			}
			l->is_waiting = 0;
		}
		l = l->next;
	}
}

int			main(int ac, char **av)
{
	t_cw		cw;
	int			turn;
	int			check;

	cw = cw_init(ac, av);
	turn = 0;
	check = 0;
	cw_parse(&cw);
	while (cw.process)
	{
		if (turn == cw.f_dump || turn == cw.f_d)
			break ;
		if (cw.cycle_to_die <= 0)
			break ;
		if (check >= cw.cycle_to_die)
			die(&cw, &check);
		exec_turn(&cw, &turn);
		if (cw.f_v == 1)
		{
			attron(COLOR_PAIR(1));
			mvprintw(0, 0,
			"Turn: %d, Process: %d, Cycle to die: %d, Instructions: %lld\n",
			turn, process_count(cw.process), cw.cycle_to_die, cw.ins);
			board_print(&cw);
			refresh();
		}
//		if (turn >= 57955)
//			sleep(2);
/*		if (cw.ins >= 76374)
		{
			ft_printf("%d \n", turn);
			sleep(2);
		}*/
		++turn;
		++check;
	}
	if (cw.f_v == 1)
		endwin();
	else if (cw.f_d != -1)
		d(&cw);
	else if (cw.f_dump != -1)
		dump(&cw);
	(cw.board) ? free(cw.board) : (void)0;
	return (1);
}
