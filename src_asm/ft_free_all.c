/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:20:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/27 14:32:04 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	ft_free_all(t_e *e)
{
	unsigned char **tmp;

	tmp = &e->header.magic;
	free_line((char **)tmp);
	free_tab(&e->tab, e->nb_instruct);
	ft_free_list_l(&e->liste);
	free_line(&e->header.prog_name);
	free_line(&e->header.comment);
	free_liste_op(&e->liste_op);
	free_line(&e->str);
	tmp = &e->header.size;
	free_line((char **)tmp);
}
