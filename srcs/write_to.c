/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:42:59 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/28 09:43:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	board_to_int(t_cw *cw, int *value, int offset)
{
	t_process	*p;

	p = cw->ap;
	((unsigned char*)value)[3] = cw->board[add_index_mod(p->pc, offset + 0)];
	((unsigned char*)value)[2] = cw->board[add_index_mod(p->pc, offset + 1)];
	((unsigned char*)value)[1] = cw->board[add_index_mod(p->pc, offset + 2)];
	((unsigned char*)value)[0] = cw->board[add_index_mod(p->pc, offset + 3)];
}

void	int_to_board(t_cw *cw, int *value, int offset)
{
	t_process		*p;
	unsigned char	color;

	p = cw->ap;
	color = (unsigned char)p->color_nb;
	cw->board[add_index_mod(p->pc, offset + 0)] = ((unsigned char*)value)[3];
	cw->board[add_index_mod(p->pc, offset + 1)] = ((unsigned char*)value)[2];
	cw->board[add_index_mod(p->pc, offset + 2)] = ((unsigned char*)value)[1];
	cw->board[add_index_mod(p->pc, offset + 3)] = ((unsigned char*)value)[0];
	cw->board_color[add_index_mod(p->pc, offset + 0)] = color;
	cw->board_color[add_index_mod(p->pc, offset + 1)] = color;
	cw->board_color[add_index_mod(p->pc, offset + 2)] = color;
	cw->board_color[add_index_mod(p->pc, offset + 3)] = color;
}