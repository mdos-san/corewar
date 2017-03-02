/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:42:04 by mdos-san          #+#    #+#             */
/*   Updated: 2017/03/02 11:54:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_bin(char *buf, int nbr, int base)
{
	int	i;
	int	mod;
	int	neg;

	i = 0;
	ft_bzero(buf, 9);
	neg = (nbr < 0) ? -1 : 1;
	while (nbr != 0)
	{
		mod = nbr % base;
		if (mod <= 9)
			buf[7 - i] = (char)(mod * neg + 48);
		else
		{
			mod -= 10;
			buf[7 - i] = (char)(mod * neg + 97);
		}
		nbr /= base;
		++i;
	}
	while (i < 8)
	{
		buf[7 - i] = '0';
		++i;
	}
}

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

static	void	ocp_part(t_cw *cw, t_process *p, int *v,
		int **pt, char *str, int dir_two, int get_index)
{
	int	ind;

	ind = 0;
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
	{
		if (get_index == 1)
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
	else if (ft_strcmp(str, "10") == 0)
	{
		if (dir_two == 1)
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
	else
		cw->param_error = 1;
}

void			ocp_parse(t_cw *cw, t_process *p,
				t_ocp ocp, int dir_two, int get_index)
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
		ocp_part(cw, p, &p->one, &p->p_one, ocp.one, dir_two, get_index);
	if (cw->nb_param >= 2)
		ocp_part(cw, p, &p->two, &p->p_two, ocp.two, dir_two, get_index);
	if (cw->nb_param >= 3)
		ocp_part(cw, p, &p->three, &p->p_three, ocp.three, dir_two, get_index);
	else if (cw->nb_param == 2 && ft_strcmp(ocp.three, "00") != 0)
		cw->param_error = 1;
	cw->nb_param = 0;
	cw->idx = 0;
}
