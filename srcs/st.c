/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:37:44 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/04 12:59:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_cw *cw, t_process *p)
{
	t_ocp	ocp;

	cw->nb_param = 2;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->get_index = 1;
	ocp_parse(cw, p, ocp);
	if (cw->param_error == 0)
	{
		if (ft_strcmp(ocp.two, "01") == 0)
			*p->p_two = *p->p_one;
		else
		{
			*p->p_two = (int)(short)(*p->p_two);
			*p->p_two = idx_mod(*p->p_two);
			int_to_board(cw, p->p_one, *p->p_two);
		}
	}
}

void	sti(t_cw *cw, t_process *p)
{
	int		sum;
	t_ocp	ocp;

	cw->nb_param = 3;
	ocp = ocp_get(cw->board[mod(p->pc, 1)]);
	cw->idx = 1;
	cw->dir_size = 2;
	ocp_parse(cw, p, ocp);
	if (ft_strcmp(ocp.two, "10") == 0)
		*p->p_two = (int)(short)(*p->p_two);
	if (ft_strcmp(ocp.three, "10") == 0)
		*p->p_three = (int)(short)(*p->p_three);
	sum = *p->p_two + *p->p_three;
	sum = idx_mod(sum);
	int_to_board(cw, p->p_one, sum);
}
