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

static int	get_int(unsigned char **v)
{
	int ret;

	((unsigned char *)&ret)[0] = *v[3];
	((unsigned char *)&ret)[1] = *v[2];
	((unsigned char *)&ret)[2] = *v[1];
	((unsigned char *)&ret)[3] = *v[0];
	return (ret);
}

int		add_index_mod(int a, int b)
{
	int	i;

	i = (a + b) % MEM_SIZE;
	return ((i >= 0) ? i : MEM_SIZE + i);
}

void	live(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("01 ") : 0;
	(cw->debug) ? ft_printf("%.2x ", cw->board[add_index_mod(p->pc, 1)]) : 0;
	(cw->debug) ? ft_printf("%.2x ", cw->board[add_index_mod(p->pc, 2)]) : 0;
	(cw->debug) ? ft_printf("%.2x ", cw->board[add_index_mod(p->pc, 3)]) : 0;
	(cw->debug) ? ft_printf("%.2x ", cw->board[add_index_mod(p->pc, 4)]) : 0;
	p->nb_live += 1;
	p->pc += 5;
}

void	ld(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("02 ") : 0;
	int	i;
	t_ocp ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	if (p->p_one[0] && p->p_two[0])
	{
		*p->p_two[0] = *p->p_one[3];
		*p->p_two[1] = *p->p_one[2];
		*p->p_two[2] = *p->p_one[1];
		*p->p_two[3] = *p->p_one[0];
		if (get_int(p->p_two) == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	st(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("03 ") : 0;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	if (p->p_one[0] && p->p_two[0])
	{
		*(p->p_two[0] + 0) = *p->p_one[3];
		*(p->p_two[0] + 1) = *p->p_one[2];
		*(p->p_two[0] + 2) = *p->p_one[1];
		*(p->p_two[0] + 3) = *p->p_one[0];
		cw->board_color[p->p_two[0] - cw->board + 0] = (unsigned char)p->color_nb;
		cw->board_color[p->p_two[0] - cw->board + 1] = (unsigned char)p->color_nb;
		cw->board_color[p->p_two[0] - cw->board + 2] = (unsigned char)p->color_nb;
		cw->board_color[p->p_two[0] - cw->board + 3] = (unsigned char)p->color_nb;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	add(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("04 ") : 0;
	int		one;
	int		two;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	p->carry = 0;
	if (p->p_one[0] && p->p_two[0] && p->p_three[0])
	{
		one = get_int(p->p_one);
		two = get_int(p->p_two);
		two = one + two;
		*p->p_three[0] = ((unsigned char *)(&two))[3];
		*p->p_three[1] = ((unsigned char *)(&two))[2];
		*p->p_three[2] = ((unsigned char *)(&two))[1];
		*p->p_three[3] = ((unsigned char *)(&two))[0];
		if (two == 0)
			p->carry = 1;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	and(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("06 ") : 0;
	int		one;
	int		two;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	p->carry = 0;
	if (p->p_one[0] && p->p_two[0] && p->p_three[0])
	{
		one = get_int(p->p_one);
		two = get_int(p->p_two);
		two = one & two;
		*p->p_three[0] = ((unsigned char *)(&two))[3];
		*p->p_three[1] = ((unsigned char *)(&two))[2];
		*p->p_three[2] = ((unsigned char *)(&two))[1];
		*p->p_three[3] = ((unsigned char *)(&two))[0];
		if (two == 0)
			p->carry = 1;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	xor(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("08 ") : 0;
	int		one;
	int		two;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0);
	if (p->p_one[0] && p->p_two[0] && p->p_three[0])
	{
		one = get_int(p->p_one);
		two = get_int(p->p_two);
//		ft_printf("one %d two %d \n", one, two);
		two = one ^ two;
		*p->p_three[0] = ((unsigned char *)(&two))[3];
		*p->p_three[1] = ((unsigned char *)(&two))[2];
		*p->p_three[2] = ((unsigned char *)(&two))[1];
		*p->p_three[3] = ((unsigned char *)(&two))[0];
		if (two == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	zjmp(t_cw *cw, t_process *p)
{
//	(cw->debug) ? ft_printf("09 ") : 0;
	unsigned short	j;

	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
//	(cw->debug) ? ft_printf("%.2x ", cw->board[p->pc + 1]) : 0;
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
//	(cw->debug) ? ft_printf("%.2x ", cw->board[p->pc + 2]) : 0;
	if (p->carry == 1)
	{
//		ft_printf("JUMP ! ");
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
	(cw->debug) ? ft_printf("0a ") : 0;
	int	i;
	int	one;
	int	two;
	int	new_addr;
	t_ocp ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	if (p->p_one[0] && p->p_two[0] && p->p_three[0])
	{
		one = get_int(p->p_one);
		two = get_int(p->p_two);
		new_addr = add_index_mod(one, two);
		*p->p_three[3] = cw->board[add_index_mod(p->pc, new_addr + 0)];
		*p->p_three[2] = cw->board[add_index_mod(p->pc, new_addr + 1)];
		*p->p_three[1] = cw->board[add_index_mod(p->pc, new_addr + 2)];
		*p->p_three[0] = cw->board[add_index_mod(p->pc, new_addr + 3)];
	}
	p->pc = add_index_mod(p->pc, i);
}

void	sti(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("0b ") : 0;
	int		sum;
	int		two;
	int		three;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1);
	if (p->p_one[0] && p->p_two[0] && p->p_three[0])
	{
		two = get_int(p->p_two);
		three = get_int(p->p_three);
		sum = two + three;
		cw->board[add_index_mod(p->pc, sum + 0)] = *p->p_one[3];
		cw->board[add_index_mod(p->pc, sum + 1)] = *p->p_one[2];
		cw->board[add_index_mod(p->pc, sum + 2)] = *p->p_one[1];
		cw->board[add_index_mod(p->pc, sum + 3)] = *p->p_one[0];
		cw->board_color[add_index_mod(p->pc, sum + 0)] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, sum + 1)] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, sum + 2)] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, sum + 3)] = (unsigned char)p->color_nb;
	}
	p->pc = add_index_mod(p->pc, i);
}

void	frk(t_cw *cw, t_process *p)
{
	(cw->debug) ? ft_printf("0C ") : 0;
	unsigned short	j;
	t_process		*child;
	int				i;

	i = 0;
	j = 0;
	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
	(cw->debug) ? ft_printf("%.2x ", cw->board[p->pc + 1]) : 0;
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
	(cw->debug) ? ft_printf("%.2x ", cw->board[p->pc + 2]) : 0;
	if (j > 32768)
		child = process_new(&cw->process, p->nb_champ, p->pc + ((j - 65535 - 1) % IDX_MOD), p->color_nb);
	else
		child = process_new(&cw->process, p->nb_champ, p->pc + (j % IDX_MOD), p->color_nb);
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}	
	p->pc = add_index_mod(p->pc, 3);
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
	return (1);
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
