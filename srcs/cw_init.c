/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:13:05 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 11:21:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	useless(t_cw *cw, t_process *process)
{
	++process->pc;
	process->pc %= MEM_SIZE;
	(void)cw;
}

static int	visu_init(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-v") == 0)
		{
			initscr();
			curs_set(FALSE);
			start_color();
			init_pair(42, COLOR_WHITE, COLOR_BLACK);
			init_pair(1, COLOR_GREEN, COLOR_BLACK);
			init_pair(2, COLOR_BLUE, COLOR_BLACK);
			init_pair(3, COLOR_RED, COLOR_BLACK);
			init_pair(4, COLOR_YELLOW, COLOR_BLACK);
			init_pair(1 + 4, COLOR_GREEN, COLOR_MAGENTA);
			init_pair(2 + 4, COLOR_BLUE, COLOR_CYAN);
			init_pair(3 + 4, COLOR_RED, COLOR_CYAN);
			init_pair(4 + 4, COLOR_YELLOW, COLOR_MAGENTA);
			init_pair(42 + 4, COLOR_WHITE, COLOR_CYAN);
			return (1);
		}
		++i;
	}
	return (0);
}

static void	init_tab(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		cw->fct_tab[i] = useless;
		++i;
	}
	cw->fct_tab[1] = live;
	cw->fct_tab[2] = ld;
	cw->fct_tab[3] = st;
	cw->fct_tab[4] = add;
	cw->fct_tab[5] = sub;
	cw->fct_tab[6] = and;
	cw->fct_tab[7] = or;
	cw->fct_tab[8] = xor;
	cw->fct_tab[9] = zjmp;
	cw->fct_tab[10] = ldi;
	cw->fct_tab[11] = sti;
	cw->fct_tab[12] = frk;
	cw->fct_tab[13] = lld;
	cw->fct_tab[14] = lldi;
	cw->fct_tab[15] = lfrk;
	cw->fct_tab[16] = aff;
}

static void	init_champ(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cw->champs[i].path = NULL;
		cw->champs[i].number = 0;
		cw->champs[i].last_live = 0;
		cw->champs[i].h.magic = 0;
		cw->champs[i].h.prog_size = 0;
		ft_bzero(cw->champs[i].h.prog_name, PROG_NAME_LENGTH + 1);
		ft_bzero(cw->champs[i].h.comment, COMMENT_LENGTH + 1);
		++i;
	}
}

t_cw		cw_init(int ac, char **av)
{
	t_cw	cw;

	cw.debug = DEBUG;
	ft_bzero(cw.board, MEM_SIZE + 1);
	ft_bzero(cw.board_color, MEM_SIZE + 1);
	ft_bzero(cw.board_ptr, MEM_SIZE + 1);
	cw.f_v = visu_init(ac, av);
	cw.f_dump = -1;
	cw.f_a = 0;
	cw.f_d = -1;
	cw.f_verbose = 0;
	cw.ac = ac;
	cw.av = av;
	cw.ins = 0;
	cw.nb_process = 0;
	cw.process = NULL;
	cw.cycle_to_die = CYCLE_TO_DIE;
	cw.turn = 1;
	cw.check = 0;
	cw.dir_size = 4;
	cw.get_index = 0;
	init_tab(&cw);
	init_champ(&cw);
	return (cw);
}
