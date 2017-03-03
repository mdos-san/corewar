/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:31:13 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/03 14:32:20 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ld(t_cw *cw, t_process *p)
{
	int		y;
	int		value;
	t_ocp	ocp;

	y = 0;
	cw->nb_param = 2;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp, 0, 1);
	value = *p->p_one;
	if (ft_strcmp(ocp.one, "11") == 0)
	{
		*p->p_one = (int)(short)(*p->p_one);
		*p->p_one = idx_mod(*p->p_one);
		board_to_int(cw, &value, *p->p_one);
	}
	if (cw->param_error == 0)
	{
		while (y < 16)
		{
			if (p->r + y == p->p_two)
				*p->p_two = value;
			++y;
		}
		p->carry = (*p->p_two == 0) ? 1 : 0;
	}
}

void	lld(t_cw *cw, t_process *p)
{
	int		y;
	t_ocp	ocp;

	y = 0;
	cw->nb_param = 2;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
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

void	ldi(t_cw *cw, t_process *p)
{
	int		new_addr;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp, 1, 0);
	new_addr = mod(*p->p_one, *p->p_two);
	board_to_int(cw, p->p_three, new_addr);
}

void	lldi(t_cw *cw, t_process *p)
{
	int		new_addr;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp, 1, 0);
	new_addr = mod(*p->p_one, *p->p_two);
	board_to_int(cw, p->p_three, new_addr);
}
