/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_typ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdorey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:52:28 by tdorey            #+#    #+#             */
/*   Updated: 2017/01/16 16:52:32 by tdorey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	get_typ(char *ptr, char *bin, t_process *p, int label) // bin label size
{
	p->decal_arg = 2;
	while (*bin)
	{
		if (*bin == '0' && *(bin + 1) == '0')
			*ptr = '0';
		else if (*bin == '0' && *(bin + 1) == '1')
		{
			*ptr = '3';
			p->decal_arg += IND_SIZE;
		}
		else if (*bin == '1' && *(bin + 1) == '0')
		{
			*ptr = '2';
			p->decal_arg += DIR_SIZE / (1 + label);
		}
		else if (*bin == '1' && *(bin + 1) == '1')
		{
			*ptr = '1';
			p->decal_arg += REG_SIZE;
		}
		bin += 2;
		ptr++;
	}
}

int 		verif_type(char *tab, t_op *data)
{
	int i;
	char *buf;
	char *tp;

	tp = data->typ_arg;
	i = data->nb_arg;
	while (i)
	{
		buf = ft_itoa_base(*tp, 2); // remplisage gauche -> 0
		if (*tab == '0' || buf[*tab - 45] == '0') // *tab - 49 + 4 // hack ascii
		{
			free(buf);
			return (0);
		}
		free(buf);		
		tp++;
		tab++;
	}
	return (1);
}
