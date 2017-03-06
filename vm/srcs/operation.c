/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:35:26 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/06 12:25:45 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_cw *cw, t_process *p)
{
	int		tmp;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->dir_size = 2;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		tmp = *p->p_one + *p->p_two;
		*p->p_three = tmp;
		if (*p->p_three == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}

void	sub(t_cw *cw, t_process *p)
{
	int		tmp;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->dir_size = 2;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		tmp = *p->p_one - *p->p_two;
		*p->p_three = tmp;
		if (*p->p_three == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}

void	and(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_three = *p->p_one & *p->p_two;
		if (*p->p_three == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}

void	or(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_three = *p->p_one | *p->p_two;
		if (*p->p_three == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}

void	xor(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		*p->p_three = *p->p_one ^ *p->p_two;
		if (*p->p_three == 0)
			p->carry = 1;
		else
			p->carry = 0;
	}
}
