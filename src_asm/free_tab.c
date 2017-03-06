/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:40:19 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/27 14:31:49 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_asm.h"

void	free_tab(t_op_ft **tab, int size)
{
	int i;

	i = 0;
	if (tab && tab[0])
	{
		while (i < size)
		{
			free_line(&tab[0][i].str);
			if (tab[0][i].ft)
				free_line(&tab[0][i].ft);
			i++;
		}
	}
	if (tab[0])
		free(tab[0]);
	tab[0] = NULL;
}
