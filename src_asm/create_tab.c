/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:20:23 by ajubert           #+#    #+#             */
/*   Updated: 2017/03/02 15:38:23 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	ft_op_ft(t_liste *tmp, t_e *e, int i)
{
	char *pl;

	pl = first_word(tmp->str);
	if (!(e->tab[i].ft = ft_strsub(pl, 0, ft_strlen(pl) - 1)))
		exit(0);
	e->tab[i].cmd = 2;
	e->tab[i].nb_octet = count_octet(tmp->str, e->tab[i].cmd);
	e->header.prog_size += e->tab[i].nb_octet;
	if (!(e->tab[i].str = ft_strdup(tmp->str)))
		exit(0);
	free_line(&pl);
}

void	ft_ft(t_liste *tmp, t_e *e, int i)
{
	char *pl;

	e->tab[i].nb_octet = 0;
	pl = first_word(tmp->str);
	if (!(e->tab[i].ft = ft_strsub(pl, 0, ft_strlen(pl) - 1)))
		exit(0);
	e->tab[i].cmd = 3;
	e->tab[i].nb_octet = 0;
	if (!(e->tab[i].str = ft_strdup(tmp->str)))
		exit(0);
	free_line(&pl);
}

void	ft_op(t_liste *tmp, t_e *e, int i)
{
	e->tab[i].cmd = 1;
	e->tab[i].nb_octet = count_octet(tmp->str, e->tab[i].cmd);
	e->header.prog_size += e->tab[i].nb_octet;
	e->tab[i].ft = NULL;
	if (!(e->tab[i].str = ft_strdup(tmp->str)))
		exit(0);
}

void	create_tab(t_e *e)
{
	t_liste		*tmp;
	int			i;

	i = -1;
	tmp = e->liste;
	while (++i < e->nb_instruct)
	{
		while (op_or_ft(tmp->str, e) == 0)
			tmp = tmp->next;
		if (op_or_ft(tmp->str, e) == 2)
			ft_op_ft(tmp, e, i);
		else if (op_or_ft(tmp->str, e) == 3)
			ft_ft(tmp, e, i);
		else
			ft_op(tmp, e, i);
		tmp = tmp->next;
	}
}
