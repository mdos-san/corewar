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

int		intro_display(t_war var, header_t *head, int ac)
{
	int i;
	
	var.i = 0;
	i = 1;
	ft_printf("Introducing contestants...\n");
	while (i < ac)
	{
		ft_printf("* Player %d, weighing %d bytes, ", i, head[i].prog_size);
		ft_printf("\"%s\" (\"%s\") !\n", head[i].prog_name, head[i].comment);
		i++;
	}
	return (1);
}
