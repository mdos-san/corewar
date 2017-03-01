/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:45 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/28 16:18:23 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		mod(int a, int b)
{
	int	i;

	i = a + b;
	i %= MEM_SIZE;
	if (i < 0)
		i = MEM_SIZE + i;
	return (i);
}

void	live(t_cw *cw, t_process *p)
{
	cw->nb_readed = 5;
	p->nb_live += 1;
	(void)cw;
}

void	ld(t_cw *cw, t_process *p)
{
	int		i;
	int		y;
	int		value;
	t_ocp	ocp;

	y = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 0, 1);
	if (ft_strcmp(ocp.one, "11") == 0)
	{
		if (p->p_one[0] > 32768)
			p->p_one[0] = (p->p_one[0] % IDX_MOD) - IDX_MOD;
		else
			p->p_one[0] = (p->p_one[0] % IDX_MOD);
		board_to_int(cw, &value, *p->p_one);
	}
	else
		value = *p->p_one;
	while (y < 16)
	{
		if (p->r + y == p->p_two)
		{
			*p->p_two = value;
			break ;
		}
		++y;
	}
	if (*p->p_two == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	st(t_cw *cw, t_process *p)
{
	int		tmp;
	t_ocp	ocp;

	ocp = ocp_get(cw->board[p->pc + 1]);
	ocp_parse(cw, p, ocp, 0, 1);
	if (!cw->param_error && cw->board[p->pc + 1] != 0)
	{
		tmp = (p->p_one[0] < 0) ? 4294967295 + p->p_one[0] + 1 : p->p_one[0];
		if (ft_strcmp(ocp.two, "01") == 0)
			p->p_two[0] = p->p_one[0];
		else
		{
			if (p->p_two[0] > 32768)
				p->p_two[0] = (p->p_two[0] % IDX_MOD) - IDX_MOD;
			else
				p->p_two[0] = (p->p_two[0] % IDX_MOD);
			int_to_board(cw, &tmp, *p->p_two);
		}
	}
}

void	add(t_cw *cw, t_process *p)
{
	int		tmp;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 1, 0);
	tmp = *p->p_one + *p->p_two;
	*p->p_three = tmp;
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	sub(t_cw *cw, t_process *p)
{
	int		tmp;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 1, 0);
	tmp = *p->p_one - *p->p_two;
	*p->p_three = tmp;
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
	cw->idx = 1;
	ocp_parse(cw, p, ocp, 0, 0);
	*p->p_three = *p->p_one & *p->p_two;
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	or(t_cw *cw, t_process *p)
{
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	cw->idx = 1;
	ocp_parse(cw, p, ocp, 0, 0);
	*p->p_three = *p->p_one | *p->p_two;
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
	cw->idx = 1;
	ocp_parse(cw, p, ocp, 0, 0);
	*p->p_three = *p->p_one ^ *p->p_two;
	if (*p->p_three == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	zjmp(t_cw *cw, t_process *p)
{
	unsigned short	j;

	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		j = j % IDX_MOD - IDX_MOD;
	else
		j = j % IDX_MOD;
	if (p->carry == 1)
	{
		p->pc += j;
		p->pc %= MEM_SIZE;
	}
	else
		cw->nb_readed = 3;
}

void	ldi(t_cw *cw, t_process *p)
{
	int		i;
	int		new_addr;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 1, 0);
	new_addr = mod(*p->p_one, *p->p_two);
	board_to_int(cw, p->p_three, new_addr);
}

void	frk(t_cw *cw, t_process *p)
{
	unsigned short	j;
	t_process		*child;
	int				i;

	i = 0;
	j = 0;
	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
	++cw->ins;
	if (j > 32768)
		j = j % IDX_MOD - IDX_MOD;
	else
		j = j % IDX_MOD;
	child = process_new(&cw->process, p->nb_champ,
			p->pc + j, p->color_nb);
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}
	child->carry = p->carry;
	child->nb_live = 1;
	cw->nb_readed = 3;
}

void	sti(t_cw *cw, t_process *p)
{
	int		sum;
	int		i;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	cw->idx = 1;
	ocp_parse(cw, p, ocp, 1, 0);
	*p->p_one = (p->p_one[0] < 0) ? 4294967295 + p->p_one[0] + 1 : p->p_one[0];
	if (ft_strcmp(ocp.two, "10") == 0)
	{
		if (*p->p_two > 32768)
			*p->p_two = *p->p_two % IDX_MOD - IDX_MOD;
		else
			*p->p_two = *p->p_two % IDX_MOD;
	}
	if (ft_strcmp(ocp.three, "10") == 0)
	{
		if (*p->p_three > 32768)
			*p->p_three = *p->p_three % IDX_MOD - IDX_MOD;
		else
			*p->p_three = *p->p_three % IDX_MOD;
	}
	sum = *p->p_two + *p->p_three;
	sum = sum % IDX_MOD;
	int_to_board(cw, p->p_one, sum);
}

void	lld(t_cw *cw, t_process *p)
{
	int		i;
	int		y;
	t_ocp	ocp;

	y = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 0, 0);
	while (y < 16)
	{
		if (p->r + y == p->p_two)
		{
			*p->p_two = *p->p_one;
			break ;
		}
		++y;
	}
	if (*p->p_two == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void	lldi(t_cw *cw, t_process *p)
{
	int		i;
	int		new_addr;
	t_ocp	ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, ocp, 1, 0);
	new_addr = mod(*p->p_one, *p->p_two);
	board_to_int(cw, p->p_three, new_addr);
}

void	lfrk(t_cw *cw, t_process *p)
{
	unsigned short	j;
	t_process		*child;
	int				i;

	i = 0;
	j = 0;
	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		child = process_new(&cw->process, p->nb_champ,
				p->pc + (j - 65535 - 1), p->color_nb);
	else
		child = process_new(&cw->process, p->nb_champ, p->pc + j, p->color_nb);
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}
}

void	aff(t_cw *cw, t_process *p)
{
	if (cw->f_a)
	{
		ft_putchar(cw->board[p->pc]);
	}
	p->pc += 2;
	p->pc %= MEM_SIZE;
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
