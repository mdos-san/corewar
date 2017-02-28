/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:30:28 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/28 08:30:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_ptr(t_cw *cw)
{
	t_process *l;

	l = cw->process;
	ft_bzero(cw->board_ptr, MEM_SIZE);
	while (l)
	{
		if (0 <= l->pc && l->pc < MEM_SIZE)
			cw->board_ptr[l->pc] = 1;
		l = l->next;
	}
}

void		board_print(t_cw *cw)
{
	int		i;
	int		is_readed;

	i = 0;
	get_ptr(cw);
	while (i < MEM_SIZE)
	{
		is_readed = 0;
		if (cw->board_color[i] == 0)
			attron(COLOR_PAIR(42));
		else
			attron(COLOR_PAIR((int)cw->board_color[i]));
		if (cw->board_ptr[i] == 1)
			is_readed = 1;
		if (cw->board_color[i] != 0)
			attron(COLOR_PAIR((int)cw->board_color[i] + ((is_readed) ? 4 : 0)));
		else if (is_readed)
			attron(COLOR_PAIR(46));
		printw("%.2x ", cw->board[i]);
		if ((i + 1) % NB_COL == 0)
			printw("\n");
		++i;
	}
}
