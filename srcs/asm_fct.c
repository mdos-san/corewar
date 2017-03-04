/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:45 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/04 13:46:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	assign_live(t_cw *cw, int number, int champ_offset)
{
	if (champ_offset < 4 && cw->champs[champ_offset].path != NULL)
	{
		if (cw->champs[champ_offset].number == number)
			cw->champs[champ_offset].last_live = cw->turn;
		else
			assign_live(cw, number, champ_offset + 1);
	}
}

void	live(t_cw *cw, t_process *p)
{
	int	champ_nb;

	board_to_int(cw, &champ_nb, 1);
	assign_live(cw, champ_nb, 0);
	cw->nb_readed = 5;
	p->nb_live += 1;
}

void	zjmp(t_cw *cw, t_process *p)
{
	short	j;

	((unsigned char *)&j)[1] = cw->board[mod(p->pc, 1)];
	((unsigned char *)&j)[0] = cw->board[mod(p->pc, 2)];
	j = idx_mod(j);
	if (p->carry == 1)
	{
		p->pc += j;
		p->pc %= MEM_SIZE;
	}
	else
		cw->nb_readed = 3;
}

void	aff(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 1;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp);
	if (!cw->f_v)
		ft_putchar((char)(*p->p_one % 256));
}

int		get_turn(unsigned char c)
{
	if (c == 1 || c == 4 || c == 5 || c == 13)
		return (10);
	else if (c == 2 || c == 3)
		return (5);
	else if (c == 6 || c == 7 || c == 8)
		return (6);
	else if (c == 9)
		return (20);
	else if (c == 10 || c == 11)
		return (25);
	else if (c == 14)
		return (50);
	else if (c == 12)
		return (800);
	else if (c == 15)
		return (1000);
	else if (c == 16)
		return (2);
	return (1);
}
