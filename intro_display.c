/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcao <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:46:51 by jcao              #+#    #+#             */
/*   Updated: 2016/12/05 11:42:30 by jcao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int		intro_display(t_war *var, header_t *head)
{
	int i;
	
	var.i = 0;
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < var->nb_champ)
	{
		ft_printf("* Player %d, weighting %d bytes, ", i + 1, head[i].prog_size);
		ft_printf("\"%s\" (\"%s\") !\n", head[i].prog_name, head[i].comment);
		i++;
	}
	return (1);
}
