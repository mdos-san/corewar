/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_liste_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:59:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 13:39:17 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	ft_fin_init(t_e *e)
{
	if (!(e->liste_op[9] = ft_strdup("ldi")))
		exit(0);
	if (!(e->liste_op[10] = ft_strdup("sti")))
		exit(0);
	if (!(e->liste_op[11] = ft_strdup("fork")))
		exit(0);
	if (!(e->liste_op[12] = ft_strdup("lld")))
		exit(0);
	if (!(e->liste_op[13] = ft_strdup("lldi")))
		exit(0);
	if (!(e->liste_op[14] = ft_strdup("lfork")))
		exit(0);
	if (!(e->liste_op[15] = ft_strdup("aff")))
		exit(0);
}

void	init_liste_op(t_e *e)
{
	if (!(e->liste_op = (char **)malloc(sizeof(char *) * NB_OP)))
		exit(0);
	if (!(e->liste_op[0] = ft_strdup("live")))
		exit(0);
	if (!(e->liste_op[1] = ft_strdup("ld")))
		exit(0);
	if (!(e->liste_op[2] = ft_strdup("st")))
		exit(0);
	if (!(e->liste_op[3] = ft_strdup("add")))
		exit(0);
	if (!(e->liste_op[4] = ft_strdup("sub")))
		exit(0);
	if (!(e->liste_op[5] = ft_strdup("and")))
		exit(0);
	if (!(e->liste_op[6] = ft_strdup("or")))
		exit(0);
	if (!(e->liste_op[7] = ft_strdup("xor")))
		exit(0);
	if (!(e->liste_op[8] = ft_strdup("zjmp")))
		exit(0);
	ft_fin_init(e);
}
