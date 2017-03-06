/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:31:13 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 12:35:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ld(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 2;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_two = *p->p_one;
		p->carry = (*p->p_two == 0) ? 1 : 0;
	}
}

static int	lld_bug(int v)
{
	int	b;

	b = v;
	((unsigned char*)&v)[0] = ((unsigned char*)&b)[2];
	((unsigned char*)&v)[1] = ((unsigned char*)&b)[3];
	((unsigned char*)&v)[2] = 0;
	((unsigned char*)&v)[3] = 0;
	return (v);
}

void		lld(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 2;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->idx = -1;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_two = *p->p_one;
		*p->p_two = lld_bug(*p->p_two);
		p->carry = (*p->p_two == 0) ? 1 : 0;
	}
}

void		ldi(t_cw *cw, t_process *p)
{
	int		new_addr;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->dir_size = 2;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_one = idx_mod(*p->p_one);
		*p->p_two = idx_mod(*p->p_two);
		new_addr = mod(*p->p_one, *p->p_two);
		board_to_int(cw, p->p_three, new_addr);
	}
}

void		lldi(t_cw *cw, t_process *p)
{
	int		new_addr;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->dir_size = 2;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		new_addr = mod(*p->p_one, *p->p_two);
		board_to_int(cw, p->p_three, new_addr);
	}
}
