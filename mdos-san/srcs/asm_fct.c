/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:45 by mdos-san          #+#    #+#             */
/*   Updated: 2017/01/11 18:44:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		add_index_mod(int a, int b)
{
	int	i;

	i = (a + b) % MEM_SIZE;
	return ((i > 0) ? i : MEM_SIZE + i);
}

void	live(t_cw *cw, t_process *p)
{
	p->pc += 4 + 1;
	p->nb_live += 1;
	(void)cw;
}

void	ld(t_cw *cw, t_process *p)
{
	int	i;
	int y;
	t_ocp ocp;

	y = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	while (y < 16)
	{
		if (p->r + y == p->p_two)
		{
			*p->p_two = *p->p_one;
			break ;
		}
		++y;
	}
	p->pc = add_index_mod(p->pc, i);
	if (*p->p_two == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	st(t_cw *cw, t_process *p)
{
	int		i;
	int		tmp;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	tmp = (p->p_one[0] < 0) ? 4294967295 + p->p_one[0] + 1 : p->p_one[0];
	cw->board[add_index_mod(p->pc, p->p_two[0] + 0)] = ((char *)(&tmp))[3];
	cw->board[add_index_mod(p->pc, p->p_two[0] + 1)] = ((char *)(&tmp))[2];
	cw->board[add_index_mod(p->pc, p->p_two[0] + 2)] = ((char *)(&tmp))[1];
	cw->board[add_index_mod(p->pc, p->p_two[0] + 3)] = ((char *)(&tmp))[0];
	cw->board_color[add_index_mod(p->pc, p->p_two[0] + 0)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, p->p_two[0] + 1)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, p->p_two[0] + 2)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, p->p_two[0] + 3)] = p->color_nb;
	p->pc = add_index_mod(p->pc, i);
}

void	add(t_cw *cw, t_process *p)
{
	int		tmp;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	tmp = *p->p_one + *p->p_two;
	*p->p_three = tmp;
	p->pc = add_index_mod(p->pc, i);
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	and(t_cw *cw, t_process *p)
{
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	*p->p_three = *p->p_one & *p->p_two;
	p->pc = add_index_mod(p->pc, i);
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	xor(t_cw *cw, t_process *p)
{
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	*p->p_three = *p->p_one ^ *p->p_two;
	p->pc = add_index_mod(p->pc, i);
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	zjmp(t_cw *cw, t_process *p)
{
	unsigned short	j;

	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (p->carry == 1)
	{
		if (j > 32768)
			p->pc = add_index_mod(p->pc, j - 65535 - 1);
		else
			p->pc = add_index_mod(p->pc, j);
	}
	else
		p->pc = add_index_mod(p->pc, 3);
}

void	ldi(t_cw *cw, t_process *p)
{
	int	i;
	int	new_addr;
	t_ocp ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	new_addr = add_index_mod(*p->p_one, *p->p_two);
	((char *)p->p_three)[3] = *(cw->board + add_index_mod(p->pc, new_addr));
	((char *)p->p_three)[2] = *(cw->board + add_index_mod(p->pc, new_addr) + 1);
	((char *)p->p_three)[1] = *(cw->board + add_index_mod(p->pc, new_addr) + 2);
	((char *)p->p_three)[0] = *(cw->board + add_index_mod(p->pc, new_addr) + 3);
	p->pc = (p->pc + i) % MEM_SIZE;
}

void	frk(t_cw *cw, t_process *p)
{
	unsigned short	j;

	j = 0;
	*(((char *)&j) + 1) = cw->board[p->pc + 1];
	*(((char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		process_add(cw, p->nb_champ, p->pc + (j - 65535 - 1), p->color_nb);
	else
		process_add(cw, p->nb_champ, p->pc + j, p->color_nb);
	p->pc = add_index_mod(p->pc, 3);
}

void	sti(t_cw *cw, t_process *p)
{
	int		sum;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	*p->p_one = (p->p_one[0] < 0) ? 4294967295 + p->p_one[0] + 1 : p->p_one[0];
	sum = *p->p_two + *p->p_three;
	cw->board[add_index_mod(p->pc, sum + 0)] = ((char *)(p->p_one))[3];
	cw->board[add_index_mod(p->pc, sum + 1)] = ((char *)(p->p_one))[2];
	cw->board[add_index_mod(p->pc, sum + 2)] = ((char *)(p->p_one))[1];
	cw->board[add_index_mod(p->pc, sum + 3)] = ((char *)(p->p_one))[0];
	cw->board_color[add_index_mod(p->pc, sum + 0)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 1)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 2)] = p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 3)] = p->color_nb;
	p->pc = add_index_mod(p->pc, i);
}

int	get_turn(unsigned char c)
{
	if (c == 1)
		return (10);
	else if (c == 2 || c == 3 || c == 4)
		return (5);
	else if (c == 6 || c == 8)
		return (6);
	else if (c == 9)
		return (20);
	else if (c == 10 || c == 11)
		return (25);
	else if (c == 12)
		return (800);
	return (0);
}

/*
**	exec
**
**	Fonction "pattern" qui init les valeur du processus pour le faire attendre un certain nombre de tour
**	quand le precessus a attendu le nombre de tour, exec lance la fonction fct pour executer l action a faire par le processus.
**
*/

void	exec(t_cw *cw, t_process *p, void (*fct)(t_cw *, t_process *))
{
	if (p->is_waiting == 0)
	{
		p->is_waiting = 1;
		p->waiting_turn = get_turn(cw->board[p->pc]);
	}
	else if (p->waiting_turn == 0)
	{
		fct(cw, p);
		p->is_waiting = 0;
	}
	--p->waiting_turn;
}
