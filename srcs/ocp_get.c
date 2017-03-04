/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:42:04 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/04 13:19:12 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_ocp			ocp_get(unsigned char ocp)
{
	char	str[9];
	t_ocp	st;

	get_bin(str, ocp, 2);
	st.one[0] = str[0];
	st.one[1] = str[1];
	st.one[2] = 0;
	st.two[0] = str[2];
	st.two[1] = str[3];
	st.two[2] = 0;
	st.three[0] = str[4];
	st.three[1] = str[5];
	st.three[2] = 0;
	return (st);
}

static void		manage_ind(t_cw *cw, int *v)
{
	int			ind;
	t_process	*p;

	ind = 0;
	p = cw->ap;
	if (cw->get_index == 1)
	{
		((unsigned char*)v)[1] = cw->board[mod(p->pc, cw->nb_readed)];
		((unsigned char*)v)[0] = cw->board[mod(p->pc, cw->nb_readed + 1)];
		cw->nb_readed += 2;
	}
	else
	{
		((unsigned char*)&ind)[1] = cw->board[mod(p->pc, cw->nb_readed)];
		((unsigned char*)&ind)[0] = cw->board[mod(p->pc, cw->nb_readed + 1)];
		ind = (int)(short)(ind);
		ind = idx_mod(ind);
		board_to_int(cw, v, ind);
		cw->nb_readed += 2;
	}
}

static void		manage_dir(t_cw *cw, int *v)
{
	t_process	*p;

	p = cw->ap;
	if (cw->dir_size == 2)
	{
		((unsigned char *)v)[1] = cw->board[mod(p->pc, cw->nb_readed)];
		((unsigned char *)v)[0] = cw->board[mod(p->pc, cw->nb_readed + 1)];
		cw->nb_readed += 2;
	}
	else
	{
		board_to_int(cw, v, cw->nb_readed);
		cw->nb_readed += 4;
	}
}

static void		ocp_part(t_cw *cw, int *v, int **pt, char *str)
{
	int			ind;
	t_process	*p;

	ind = 0;
	p = cw->ap;
	if (ft_strcmp(str, "01") == 0)
	{
		if (1 <= cw->board[mod(p->pc, cw->nb_readed)]
				&& cw->board[mod(p->pc, cw->nb_readed)] <= 16)
			*pt = p->r + (cw->board[mod(p->pc, cw->nb_readed)]) - 1;
		else
			cw->param_error = 1;
		++cw->nb_readed;
	}
	else if (ft_strcmp(str, "11") == 0)
		manage_ind(cw, v);
	else if (ft_strcmp(str, "10") == 0)
		manage_dir(cw, v);
	else
		cw->param_error = 1;
}

void			ocp_parse(t_cw *cw, t_process *p, t_ocp ocp)
{
	cw->ap = p;
	p->p_one = &p->one;
	p->p_two = &p->two;
	p->p_three = &p->three;
	p->one = 0;
	p->two = 0;
	p->three = 0;
	cw->param_error = 0;
	cw->nb_readed += 2;
	if (cw->nb_param >= 1)
		ocp_part(cw, &p->one, &p->p_one, ocp.one);
	if (cw->nb_param >= 2)
		ocp_part(cw, &p->two, &p->p_two, ocp.two);
	if (cw->nb_param >= 3)
		ocp_part(cw, &p->three, &p->p_three, ocp.three);
	else if (cw->nb_param == 2 && ft_strcmp(ocp.three, "00") != 0)
		cw->param_error = 1;
	cw->nb_param = 0;
	cw->idx = 0;
	cw->dir_size = 4;
	cw->get_index = 0;
}
