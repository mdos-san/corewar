/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 14:32:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 13:37:10 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

int		count_nb_instruct(t_liste *liste, t_e *e)
{
	int r;

	r = 0;
	while (liste)
	{
		if (op_or_ft(liste->str, e) != 0)
			r++;
		liste = liste->next;
	}
	return (r);
}
