/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:44:45 by mdos-san          #+#    #+#             */
/*   Updated: 2017/02/26 10:35:06 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		add_index_mod(int a, int b)
{
	int	i;

	i = (a + b) % MEM_SIZE;
	return ((i >= 0) ? i : MEM_SIZE + i);
}

void	live(t_cw *cw, t_process *p)
{
	p->pc += 5;
	p->nb_live += 1;
	(void)cw;
}

void	ld(t_cw *cw, t_process *p)
{
	int	i;
	int y;
	int	value;
	t_ocp ocp;

	y = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0, 1);
	if (ft_strcmp(ocp.one, "11") == 0)
	{
		if (p->p_one[0] > 32768)
			p->p_one[0] = (p->p_one[0] % IDX_MOD) - IDX_MOD;
		else
			p->p_one[0] = (p->p_one[0] % IDX_MOD);
		((unsigned char*)&value)[3] = cw->board[add_index_mod(p->pc, p->p_one[0] + 0)];
		((unsigned char*)&value)[2] = cw->board[add_index_mod(p->pc, p->p_one[0] + 1)];
		((unsigned char*)&value)[1] = cw->board[add_index_mod(p->pc, p->p_one[0] + 2)];
		((unsigned char*)&value)[0] = cw->board[add_index_mod(p->pc, p->p_one[0] + 3)];
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
	ocp_parse(cw, p, &i, ocp, 0, 1);
	tmp = (p->p_one[0] < 0) ? 4294967295 + p->p_one[0] + 1 : p->p_one[0];
	if (ft_strcmp(ocp.two, "01") == 0)
		p->p_two[0] = p->p_one[0];
	else
	{
		if (p->p_two[0] > 32768)
			p->p_two[0] = (p->p_two[0] % IDX_MOD) - IDX_MOD;
		else
			p->p_two[0] = (p->p_two[0] % IDX_MOD);
		cw->board[add_index_mod(p->pc, (p->p_two[0] + 0))] = ((unsigned char *)(&tmp))[3];
		cw->board[add_index_mod(p->pc, (p->p_two[0] + 1))] = ((unsigned char *)(&tmp))[2];
		cw->board[add_index_mod(p->pc, (p->p_two[0] + 2))] = ((unsigned char *)(&tmp))[1];
		cw->board[add_index_mod(p->pc, (p->p_two[0] + 3))] = ((unsigned char *)(&tmp))[0];
		cw->board_color[add_index_mod(p->pc, (p->p_two[0] + 0))] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, (p->p_two[0] + 1))] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, (p->p_two[0] + 2))] = (unsigned char)p->color_nb;
		cw->board_color[add_index_mod(p->pc, (p->p_two[0] + 3))] = (unsigned char)p->color_nb;
	}
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
	ocp_parse(cw, p, &i, ocp, 1, 0);
	tmp = *p->p_one + *p->p_two;
	*p->p_three = tmp;
	p->pc = add_index_mod(p->pc, i);
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
	ocp_parse(cw, p, &i, ocp, 1, 0);
	tmp = *p->p_one - *p->p_two;
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
	cw->idx = 1;
	ocp_parse(cw, p, &i, ocp, 0, 0);
	*p->p_three = *p->p_one & *p->p_two;
	p->pc = add_index_mod(p->pc, i);
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
	ocp_parse(cw, p, &i, ocp, 0, 0);
	*p->p_three = *p->p_one | *p->p_two;
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
	cw->idx = 1;
	ocp_parse(cw, p, &i, ocp, 0, 0);
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

	*(((unsigned char *)&j) + 1) = cw->board[p->pc + 1];
	*(((unsigned char *)&j)) = cw->board[p->pc + 2];
	if (j > 32768)
		j = j % IDX_MOD - IDX_MOD;
	else
		j = j % IDX_MOD;
	if (p->carry == 1)
		p->pc = add_index_mod(p->pc, j);
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
	ocp_parse(cw, p, &i, ocp, 1, 0);
	new_addr = add_index_mod(*p->p_one, *p->p_two);
	((unsigned char *)p->p_three)[3] = *(cw->board + add_index_mod(p->pc, new_addr));
	((unsigned char *)p->p_three)[2] = *(cw->board + add_index_mod(p->pc, new_addr) + 1);
	((unsigned char *)p->p_three)[1] = *(cw->board + add_index_mod(p->pc, new_addr) + 2);
	((unsigned char *)p->p_three)[0] = *(cw->board + add_index_mod(p->pc, new_addr) + 3);
	p->pc = (p->pc + i) % MEM_SIZE;
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
	if (j > 32768)
		j = j % IDX_MOD - IDX_MOD;
	else
		j = j % IDX_MOD;
	child = process_new(&cw->process, p->nb_champ, add_index_mod(p->pc, j), p->color_nb);
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}	
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
	cw->idx = 1;
	ocp_parse(cw, p, &i, ocp, 1, 0);
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
//	ft_printf("sum a: %d %d %d\n", sum, *p->p_two, *p->p_three);
//	if (sum < 0)
//		sum = sum % IDX_MOD - IDX_MOD;
//	else
	sum = sum % IDX_MOD;
//	ft_printf("sum b: %d %d %d\n", sum, *p->p_two, *p->p_three);
	cw->board[add_index_mod(p->pc, sum + 0)] = ((unsigned char *)(p->p_one))[3];
	cw->board[add_index_mod(p->pc, sum + 1)] = ((unsigned char *)(p->p_one))[2];
	cw->board[add_index_mod(p->pc, sum + 2)] = ((unsigned char *)(p->p_one))[1];
	cw->board[add_index_mod(p->pc, sum + 3)] = ((unsigned char *)(p->p_one))[0];
	cw->board_color[add_index_mod(p->pc, sum + 0)] = (unsigned char)p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 1)] = (unsigned char)p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 2)] = (unsigned char)p->color_nb;
	cw->board_color[add_index_mod(p->pc, sum + 3)] = (unsigned char)p->color_nb;
	p->pc = add_index_mod(p->pc, i);
}

void	lld(t_cw *cw, t_process *p)
{
	int	i;
	int y;
	t_ocp ocp;

	y = 0;
	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 0, 0);
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

void	lldi(t_cw *cw, t_process *p)
{
	int	i;
	int	new_addr;
	t_ocp ocp;

	i = 1;
	ocp = ocp_get(cw->board[p->pc + i]);
	++i;
	ocp_parse(cw, p, &i, ocp, 1, 0);
	new_addr = add_index_mod(*p->p_one, *p->p_two);
	((unsigned char *)p->p_three)[3] = *(cw->board + add_index_mod(p->pc, new_addr));
	((unsigned char *)p->p_three)[2] = *(cw->board + add_index_mod(p->pc, new_addr) + 1);
	((unsigned char *)p->p_three)[1] = *(cw->board + add_index_mod(p->pc, new_addr) + 2);
	((unsigned char *)p->p_three)[0] = *(cw->board + add_index_mod(p->pc, new_addr) + 3);
	p->pc = (p->pc + i) % MEM_SIZE;
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
		child = process_new(&cw->process, p->nb_champ, p->pc + (j - 65535 - 1), p->color_nb);
	else
		child = process_new(&cw->process, p->nb_champ, p->pc + j, p->color_nb);
	while (i < 16)
	{
		child->r[i] = p->r[i];
		++i;
	}	
	p->pc = add_index_mod(p->pc, 3);
}

void	aff(t_cw *cw, t_process *p)
{
	ft_putchar(cw->board[p->pc]);
}

int	get_turn(unsigned char c)
{
	if (c == 1 || c == 13)
		return (10);
	else if (c == 2 || c == 3 || c == 4 || c == 5)
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
	return (0);
}
